/****************************************************
 * @file    02_server_epoll.c
 * @brief   epoll实现的简单聊天室
 *          支持超时退出、断线重连
 * @author  bitofux
 * @date    2025-10-08
 ****************************************************/
#include <bits/time.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/epoll.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <time.h>
#include <errno.h>

#include "lib/header.h"

int main(int argc, char** argv) {
    if (argc < 3 || argc > 3) {
        fprintf(stderr, "usage: exec ip port\n");
        exit(-1);
    }

    int sock_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sock_fd < 0) {
        perror("socket");
        exit(-1);
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &server_addr.sin_addr) < 0) {
        perror("inet_pton");
        exit(-1);
    }

    int reuse = 1;
    if (setsockopt(sock_fd, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse)) < 0) {
        perror("setsockopt");
        exit(-1);
    }

    if (bind(sock_fd, (const struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        exit(-1);
    }

    if (listen(sock_fd, 64) < 0) {
        perror("listen");
        exit(-1);
    }

    // 保存连接对象的动态顺序表变量
    dym_seq_t dym_seq;
    // 初始化这个顺序表，并设置容量
    init(&dym_seq, 10);
    // 用户态缓冲区
    char buf[1024] = {0};
    // 客户端ip地址保存
    char buf_ip[INET_ADDRSTRLEN] = {0};

    // 创建一个epoll实例
    int ep_fd = epoll_create1(EPOLL_CLOEXEC);
    if (ep_fd < 0) {
        perror("epoll_create1");
        exit(-1);
    }
    struct epoll_event event = {.events = EPOLLIN, .data.fd = sock_fd};
    epoll_ctl(ep_fd, EPOLL_CTL_ADD, sock_fd, &event);

    // 用户态保存epoll返回的就绪列表
    struct epoll_event events[10];

    while (1) {
        bzero(events, sizeof(events));
        int ready_nums = epoll_wait(ep_fd, events, 10, 1000);
        // 获取就绪时间
        struct timespec start;
        clock_gettime(CLOCK_MONOTONIC, &start);
        for (int i = 0; i < ready_nums; ++i) {
            int fd = events[i].data.fd;
            if (fd == sock_fd) {
                struct sockaddr_in client_addr;
                socklen_t len = sizeof(client_addr);
                int ret_accept;
                do {
                    ret_accept = accept(sock_fd, (struct sockaddr*)&client_addr, &len);
                } while (ret_accept < 0 && errno == EINTR);
                // 将其添加到监听
                event.data.fd = ret_accept;
                epoll_ctl(ep_fd, EPOLL_CTL_ADD, ret_accept, &event);
                // 生成一个匿名的连接对象将其添加到动态顺序表
                push_back(&dym_seq,
                          (conn_t){.fd = ret_accept, .start = start, .client_addr = client_addr});
                continue;
            } else {
                bzero(buf, sizeof(buf));
                int ret_read = recv(fd, buf, sizeof(buf), 0);
                if (ret_read < 0) {
                    perror("read");
                    // 移除监听列表
                    epoll_ctl(ep_fd, EPOLL_CTL_DEL, fd, NULL);
                    // 关闭文件描述符
                    close(fd);
                    // 在顺序表中删除
                    erase(&dym_seq, get_index(&dym_seq, fd));
                    continue;
                } else if (ret_read == 0) {
                    // 移除监听列表
                    epoll_ctl(ep_fd, EPOLL_CTL_DEL, fd, NULL);
                    // 关闭文件描述符
                    close(fd);
                    // 在顺序表中删除
                    erase(&dym_seq, get_index(&dym_seq, fd));
                    continue;
                }
                // 更新就绪时间

                for (int i = 0; i < dym_seq.size; ++i) {
                    if (fd != dym_seq.conn_data[i].fd) {
                        (void)send(dym_seq.conn_data[i].fd, buf, ret_read, 0);
                    } else {
                        dym_seq.conn_data[i].start = start;
                    }
                }
            }
        }
        // 超时退出
        struct timespec end;
        clock_gettime(CLOCK_MONOTONIC, &end);
        int size = dym_seq.size;
        for (int i = 0; i < size; ++i) {
            double el = (end.tv_sec - dym_seq.conn_data[i].start.tv_sec) +
                        (end.tv_nsec - dym_seq.conn_data[i].start.tv_nsec) / 1e9;
            // 客户端的ip地址
            inet_ntop(AF_INET, &dym_seq.conn_data[i].client_addr.sin_addr, buf_ip, sizeof(buf_ip));
            uint16_t port = ntohs(dym_seq.conn_data[i].client_addr.sin_port);
            printf("%d,%s:%hu->%0.6f\n", dym_seq.conn_data[i].fd, buf_ip, port, el);
            if (el > 20.0) {
                // 移除监听列表
                epoll_ctl(ep_fd, EPOLL_CTL_DEL, dym_seq.conn_data[i].fd, NULL);
                // 关闭fd
                close(dym_seq.conn_data[i].fd);
                // 在顺序表中移除
                erase(&dym_seq, get_index(&dym_seq, dym_seq.conn_data[i].fd));
            }
        }
    }
}
