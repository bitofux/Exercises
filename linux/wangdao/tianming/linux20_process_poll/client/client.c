/****************************************************
 * @file    client.c
 * @brief   测试客户端
 * @author  bitofux
 * @date    2025-10-28
 ****************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/epoll.h>
#include <arpa/inet.h>
#include <netinet/in.h>

int main(int argc, char** argv) {
    if (argc < 3) {
        fprintf(stderr, "usage: exec ip port\n");
        return -1;
    }
    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd < 0) {
        perror("socket");
        return -1;
    }
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    (void)inet_pton(AF_INET, argv[1], &server_addr.sin_addr);

    int ret_conn = connect(sock_fd, (const struct sockaddr*)&server_addr, sizeof(server_addr));

    send(sock_fd, "hello", strlen("hello"), 0);

    char buf[10] = {0};
    recv(sock_fd, buf, sizeof buf, 0);
    printf("buf: %s\n", buf);
    while (1) {
    }
}
