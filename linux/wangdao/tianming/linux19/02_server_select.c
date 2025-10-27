/****************************************************
 * @file    02_server_select.c
 * @brief   简单的聊天室服务器: 超时断开 断线重连
 * @author  bitofux
 * @date    2025-10-05
 ****************************************************/
#include <stdint.h>
#include <stdio.h>
#include <strings.h>
#include <sys/select.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <time.h>

#include "./lib/header.h"

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
    int ret_pton = inet_pton(AF_INET, argv[1], &server_addr.sin_addr);
    if (ret_pton < 0) {
        perror("inet_pton");
    }

    int reuse = 1;
    int ret_setsockopt = setsockopt(sock_fd, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse));
    if (ret_setsockopt < 0) {
        perror("setsockopt");
    }

    int ret_bind = bind(sock_fd, (const struct sockaddr*)&server_addr, sizeof(server_addr));
    if (ret_bind < 0) {
        perror("bind");
    }

    int ret_listen = listen(sock_fd, 64);
    if (ret_listen < 0) {
        perror("listen");
        exit(-1);
    }

    // 定义一个动态顺序表
    dym_seq_t dym_seq;
    bzero(&dym_seq, sizeof(dym_seq));
    // 初始化顺序表 容量64
    init(&dym_seq, 64);
    // 用户态缓冲区
    char buf[1024] = {0};
    // 暂存某个连接对象的ip地址的缓冲区
    char buf_ip[INET_ADDRSTRLEN] = {0};

    // 定义两个fd_set集合
    fd_set readfds, basefds;
    FD_ZERO(&readfds);
    FD_ZERO(&basefds);

    // 将率先需要监听的文件描述符添加到集合中
    FD_SET(sock_fd, &basefds);

    while (1) {
        struct timeval tv = {.tv_sec = 1, .tv_usec = 0};
        bzero(&readfds, sizeof(readfds));
        memcpy(&readfds, &basefds, sizeof(readfds));

        int ret_select;
        do {
            ret_select = select(64, &readfds, NULL, NULL, &tv);
        } while (ret_select < 0 && errno == EINTR);

        if (FD_ISSET(sock_fd, &readfds)) {
            struct sockaddr_in client_addr;
            socklen_t len = sizeof(client_addr);
            int net_fd;
            do {
                net_fd = accept(sock_fd, (struct sockaddr*)&client_addr, &len);
            } while (net_fd < 0 && errno == EINTR);
            // 保存此时这个连接对象的时间
            struct timespec start;
            clock_gettime(CLOCK_MONOTONIC, &start);
            // 添加到监听集合
            FD_SET(net_fd, &basefds);
            // 添加到动态顺序表中 使用c99的复合字面量
            push_back(&dym_seq, (conn_t){.fd = net_fd, .start = start, .client_addr = client_addr});
            continue;
        }
        for (int i = 0; i < dym_seq.size; ++i) {
            if (FD_ISSET(dym_seq.conn_data[i].fd, &readfds)) {
                bzero(buf, sizeof(buf));
                int ret_recv = recv(dym_seq.conn_data[i].fd, buf, sizeof(buf), 0);
                if (ret_recv < 0) {
                    perror("recv");
                    continue;
                } else if (ret_recv == 0) {
                    // 移除监听
                    FD_CLR(dym_seq.conn_data[i].fd, &basefds);
                    // 动态顺序表中删除
                    erase(&dym_seq, get_index(&dym_seq, dym_seq.conn_data[i].fd));
                    close(dym_seq.conn_data[i].fd);
                    continue;
                }
                // 更新就绪的时间
                clock_gettime(CLOCK_MONOTONIC, &dym_seq.conn_data[i].start);
                // 将读取的数据分发给其他人
                for (int j = 0; j < dym_seq.size; ++j) {
                    if (dym_seq.conn_data[j].fd != dym_seq.conn_data[i].fd) {
                        int ret_send = send(dym_seq.conn_data[j].fd, buf, ret_recv, 0);
                        if (ret_send < 0) {
                            perror("send");
                            continue;
                        }
                    }
                }
            }
        }

        // 超时退出
        // printf("sss\n");
        struct timespec end;
        printf("%d\n", dym_seq.size);
        int size = dym_seq.size;
        for (int i = 0; i < size; ++i) {
            clock_gettime(CLOCK_MONOTONIC, &end);
            double el = (end.tv_sec - dym_seq.conn_data[i].start.tv_sec) +
                        (end.tv_nsec - dym_seq.conn_data[i].start.tv_nsec) / 1e9;
            uint16_t port = ntohs(dym_seq.conn_data[i].client_addr.sin_port);
            bzero(buf_ip, sizeof(buf_ip));
            (void)inet_ntop(AF_INET, &dym_seq.conn_data[i].client_addr.sin_addr, buf_ip,
                            sizeof(buf_ip));
            printf("%d->%s:%hu:%.6f\n", dym_seq.conn_data[i].fd, buf_ip, port, el);
            if (el > 20.0) {
                // 移除监听列表
                FD_CLR(dym_seq.conn_data[i].fd, &basefds);
                // 关闭描述符
                close(dym_seq.conn_data[i].fd);
                // 动态顺序表中删除
                erase(&dym_seq, get_index(&dym_seq, dym_seq.conn_data[i].fd));
            }
        }
    }
}
