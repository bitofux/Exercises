/****************************************************
 * @file    main.c
 * @brief   服务器主源文件
 * @author  bitofux
 * @date    2025-11-01
 ****************************************************/
#include <unistd.h>
#include "header.h"

int main(int argc, char** argv) {
    if (argc < 3) {
        fprintf(stderr, "usage: exec ip port\n");
        return -1;
    }

    // 1. 定义一个数组:保存每个进程的属性信息
    proc_t list[PROC_NUM];
    memset(list, 0, sizeof(list));

    // 2. 初始化进程池
    if (init_process_poll(list, PROC_NUM) < 0) {
        fprintf(stderr, "init_process_poll failed\n");
        return -1;
    }

    // 3. 初始化tcp连接
    int listen_fd = 0;
    if (init_tcp_connect(&listen_fd, argv[1], atoi(argv[2])) < 0) {
        fprintf(stderr, "init_tcp_connect failed\n");
        return -1;
    }

    // 4. 创建epoll实例并添加监听
    int ep_fd = epoll_create1(EPOLL_CLOEXEC);
    if (ep_fd < 0) {
        perror("epoll_create1");
        return -1;
    }
    // 4.1 添加listen_fd
    if (add_fd_to_ep(ep_fd, listen_fd, EPOLLIN) < 0) {
        fprintf(stderr, "add_fd_to_ep failed\n");
        return -1;
    }
    // 4.2 添加父进程用于子进程通信的文件对象
    for (int i = 0; i < PROC_NUM; ++i) {
        if (add_fd_to_ep(ep_fd, list[i].local_fd, EPOLLIN) < 0) {
            fprintf(stderr, "add_fd_to_ep failed\n");
            return -1;
        }
    }

    // 5. 定义用户态缓冲区和用于存放就绪文件对象的数组
    char buf[1024] = {0};
    struct epoll_event events[READY_NUM];

    while (1) {
        memset(events, 0, sizeof(events));
        int ready_nums = epoll_wait(ep_fd, events, READY_NUM, -1);
        if (ready_nums < 0) {
            perror("epoll_wait");
            return -1;
        }
        // 6. 遍历就绪列表
        for (int i = 0; i < ready_nums; ++i) {
            int fd = events[i].data.fd;
            if (fd == listen_fd) {
                int net_fd = -1;
                do {
                    net_fd = accept(listen_fd, NULL, NULL);
                } while (net_fd < 0 && errno == EAGAIN);
                // 7. 将这个fd发送给空闲的子进程
                send_fd_to_chi_proc(list, PROC_NUM, net_fd);
                close(net_fd);
            } else {
                bzero(buf, sizeof(buf));
                int ret = recv(fd, buf, sizeof(buf), 0);
                printf("recv from child proc: %s\n", buf);
                // 子进程完成任务之后,将其状态设为NOT_BUSY
                for (int i = 0; i < PROC_NUM; ++i) {
                    if (fd == list[i].local_fd) {
                        list[i].status = NOT_BUSY;
                    }
                }
            }
        }
    }
}
