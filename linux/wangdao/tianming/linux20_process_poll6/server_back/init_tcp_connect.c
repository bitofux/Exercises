/****************************************************
 * @file    init_tcp_connect.c
 * @brief   初始化tcp连接
 * @author  bitofux
 * @date    2025-10-28
 ****************************************************/
#include "header.h"
#include <asm-generic/socket.h>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int init_tcp_connect(const char* ip, const uint16_t port) {
    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd < 0) {
        perror("socket");
        return -1;
    }
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    (void)inet_pton(AF_INET, ip, &server_addr.sin_addr);

    int reuse = 1;
    (void)setsockopt(sock_fd, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse));

    if (bind(sock_fd, (const struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        return -1;
    }
    if (listen(sock_fd, 64) < 0) {
        perror("listen");
        return -1;
    }
    return sock_fd;
}
