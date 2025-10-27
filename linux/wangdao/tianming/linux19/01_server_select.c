/****************************************************
 * @file    01_server_select.c
 * @brief   使用select 服务器监听键盘输入和用于与服务器通信的
 *          sockfd
 * @author  bitofux
 * @date    2025-10-05
 ****************************************************/
#include <stdio.h>
#include <strings.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include <sys/select.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>

int main(int argc, char** argv) {
    if (argc < 3 || argc > 3) {
        fprintf(stderr, "usage: exec ip port\n");
        exit(-1);
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
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

    int reuse = 0;
    int ret_setsockopt = setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse));
    if (ret_setsockopt < 0) {
        perror("setsockopt");
        exit(-1);
    }

    int ret_bind = bind(sockfd, (const struct sockaddr*)&server_addr, sizeof(server_addr));
    if (ret_bind < 0) {
        perror("bind");
        exit(-1);
    }

    int ret_listen = listen(sockfd, 64);
    if (ret_listen < 0) {
        perror("listen");
        exit(-1);
    }

    struct sockaddr_in client_addr;
    socklen_t len = sizeof(client_addr);
    int net_fd = 0;
    do {
        net_fd = accept(sockfd, (struct sockaddr*)&client_addr, &len);
    } while (net_fd < 0 && errno == EINTR);

    // 数据缓冲区
    char buf[1024] = {0};
    // 客户端ip地址
    char buf_addr[INET_ADDRSTRLEN] = {0};

    fd_set readfds;
    fd_set basefds;
    FD_ZERO(&basefds);
    FD_SET(STDIN_FILENO, &basefds);
    FD_SET(net_fd, &basefds);
    while (1) {
        bzero(&readfds, sizeof(readfds));
        memcpy(&readfds, &basefds, sizeof(basefds));
        int ret_select = 0;
        do {
            ret_select = select(net_fd + 1, &readfds, NULL, NULL, NULL);
        } while (ret_select < 0 && errno == EINTR);
        if (FD_ISSET(net_fd, &readfds)) {
            bzero(buf, sizeof(buf));
            int ret_recv = recv(net_fd, buf, sizeof buf, 0);
            if (ret_recv < 0) {
                perror("recv");
                exit(-1);
            }
            // 获取客户端地址
            bzero(buf_addr, sizeof buf_addr);
            if (NULL == inet_ntop(AF_INET, &client_addr.sin_addr, buf_addr, sizeof(buf_addr))) {
                perror("inet_pton");
            }
            printf("%s:%hu:%s", buf_addr, ntohs(client_addr.sin_port), buf);
        }
        if (FD_ISSET(STDIN_FILENO, &readfds)) {
            bzero(buf, sizeof(buf));
            int ret_read = read(STDIN_FILENO, buf, sizeof(buf));
            if (ret_read < 0) {
                perror("read");
            } else if (ret_read == 0) {
                printf("clint is broken\n");
                break;
            }
            int ret_send = send(net_fd, buf, ret_read, 0);
            if (ret_send < 0) {
                perror("send");
            }
        }
    }
}
