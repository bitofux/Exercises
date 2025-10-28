/****************************************************
 * @file    main.c
 * @brief   服务器主模块
 * @author  bitofux
 * @date    2025-10-28
 ****************************************************/
#include "header.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/fcntl.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <sys/epoll.h>

#define NUM 4
int main(int argc, char** argv) {
    if (argc < 3) {
        fprintf(stderr, "usage: exec ip port\n");
        return -1;
    }
    // 创建一个有4个元素的数组保存每个进程的信息
    child_proc_t proc_list[NUM];
    memset(proc_list, 0, sizeof(proc_list));

    // 利用socketpair创建两个文件对象用于父子进程通信
    int sp[2] = {0};
    int ret_sp = socketpair(AF_LOCAL, SOCK_STREAM, 0, sp);
    if (ret_sp < 0) {
        perror("socketpair");
        return -1;
    }

    // 初始化进程池,创建多个进程并初始化每个进程的信息
    if (init_process_poll(proc_list, NUM, sp) < 0) {
        fprintf(stderr, "init_process_poll faild\n");
        return -1;
    }

    // 创建用于监听的文件对象、绑定ip_port、监听
    int sock_fd = init_tcp_connect(argv[1], atoi(argv[2]));

    // 创建epoll实例
    int ep = epoll_create1(EPOLL_CLOEXEC);
    if (ep < 0) {
        perror("epoll_create1");
        return -1;
    }

    // 添加用于建立连接的监听对象
    add_event(ep, sock_fd, EPOLLIN);
    // 添加用于子进程通信的文件对象
    for (int i = 0; i < NUM; ++i) {
        add_event(ep, proc_list[i].fd, EPOLLIN);
    }

    // 缓冲区
    char buf[1024] = {0};
    // 就绪列表
    struct epoll_event events[4];
    while (1) {
        memset(events, 0, sizeof(events));
        int epoll_nums = epoll_wait(ep, events, 4, -1);
        if (epoll_nums < 0) {
            perror("epoll_wait");
            return -1;
        }
        for (int i = 0; i < epoll_nums; ++i) {
            int fd = events[i].data.fd;
            if (fd == sock_fd) {
                int net_fd = 0;
                do {
                    net_fd = accept(sock_fd, NULL, NULL);
                } while (net_fd < 0 && errno == EINTR);
                send_fd_to_son(proc_list, NUM, net_fd, sp);

                // 关闭父进程对通信对象的引用,这样子进程close的时候,客户端可以感知到
                // 否则,子进程close的时候,这个文件对象还有其他进程引用,是不会主动发起
                // 四次握手的
                close(net_fd);
            } else {
                recv(sp[1], buf, sizeof(buf), 0);
                printf("%d->buf: %s\n", getpid(), buf);
                // 子进程完成任务发送数据给父进程
                // 遍历数组中的进程,将完成任务的进程的状态设置为空闲
                for (int i = 0; i < NUM; ++i) {
                    if (proc_list[i].fd == fd) {
                        proc_list[i].status = IDLESSE;
                        break;
                    }
                }
            }
        }
    }
}
