#include <stdio.h>
#include <strings.h>
#include <sys/epoll.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdbool.h>
#include "sys_header.h"

int main(int argc, char** argv) {
    if (argc < 3 || argc > 3) {
        fprintf(stderr, "usage: exec ip port\n");
        return -1;
    }

    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd < 0) {
        perror("socket");
        return -1;
    }

    struct sockaddr_in addr_in = {.sin_family = AF_INET,
                                  .sin_port = htons(atoi(argv[2])),
                                  .sin_addr.s_addr = inet_addr(argv[1])};

    int ret_conn = connect(sock_fd, (struct sockaddr*)&addr_in, sizeof(addr_in));
    if (ret_conn < 0) {
        perror("connect");
        return -1;
    }

    // 创建一个epoll实例 -- 文件对象
    int ep_fd = epoll_create1(EPOLL_CLOEXEC);
    if (ep_fd < 0) {
        perror("epoll_create1");
        return -1;
    }
    struct epoll_event event = {.events = EPOLLIN, .data.fd = STDIN_FILENO};
    // 添加到监听集合
    epoll_ctl(ep_fd, EPOLL_CTL_ADD, STDIN_FILENO, &event);
    event.data.fd = sock_fd;
    epoll_ctl(ep_fd, EPOLL_CTL_ADD, sock_fd, &event);

    // 创建一个struct epoll_event类型的数组用于内核拷贝就绪
    // 集合中的数据到用户态
    struct epoll_event events[2];
    char buf[1024] = {0};
    bool flag = true;
    while (1) {
        // 清空用户态保存的就绪集合
        bzero(&events, sizeof(events));
        // 调用epoll_wait
        int epoll_num = epoll_wait(ep_fd, events, 2, -1);

        // 遍历真正的就绪集合
        for (int i = 0; i < epoll_num; ++i) {
            // 保存文件描述符对应的文件对象就绪的状态
            // uint32_t eve = events[i].events;
            // 保存文件描述符
            int fd = events[i].data.fd;
            if (fd == STDIN_FILENO) {
                bzero(buf, sizeof(buf));
                // 读取数据
                int ret_read = read(fd, buf, sizeof(buf));
                if (ret_read < 0) {
                    perror("read");
                    return -1;
                }
                // 发送数据
                int ret_send = send(sock_fd, buf, ret_read, 0);
                if (ret_send < 0) {
                    perror("send");
                    return -1;
                }
            } else if (fd == sock_fd) {
                bzero(buf, sizeof(buf));
                // 读取数据
                int ret_recv = recv(fd, buf, sizeof(buf), 0);
                if (ret_recv == 0) {
                    flag = false;
                    printf("server is closed\n");
                    break;
                }
                if (ret_recv < 0) {
                    perror("recv");
                    return -1;
                }
                printf("buf: %s", buf);
            }
        }
        if (flag == false) {
            break;
        }
    }
}
