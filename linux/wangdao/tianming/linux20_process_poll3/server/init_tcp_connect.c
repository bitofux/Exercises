/****************************************************
 * @file    init_tcp_connect.c
 * @brief   初始化tcp连接
 * @author  bitofux
 * @date    2025-11-01
 ****************************************************/
#include "header.h"

int init_tcp_connect(int* fd, const char* ip, const unsigned short port) {
    *fd = socket(AF_INET, SOCK_STREAM, 0);
    if (*fd < 0) {
        perror("socket");
        return -1;
    }
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    (void)inet_pton(AF_INET, ip, &server_addr.sin_addr);

    int reuse = 1;
    if (setsockopt(*fd, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse)) < 0) {
        perror("setsockopt");
        return -1;
    }

    if (bind(*fd, (const struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        return -1;
    }

    if (listen(*fd, 64) < 0) {
        perror("listen");
        return -1;
    }
    return 0;
}
