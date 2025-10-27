/****************************************************
 * @file    02_client_select.c
 * @brief   客户端
 * @author  bitofux
 * @date    2025-10-07
 ****************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <strings.h>
#include <time.h>

#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/select.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, char** argv) {
    if (argc < 3 || argc > 3) {
        fprintf(stderr, "usage:exec ip port\n");
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
    int ret_inet_pton = inet_pton(AF_INET, argv[1], &server_addr.sin_addr);
    if (ret_inet_pton < 0) {
        perror("inet_pton");
        exit(-1);
    }

    int ret_conn = connect(sock_fd, (const struct sockaddr*)&server_addr, sizeof(server_addr));
    if (ret_conn < 0) {
        perror("connect");
        exit(-1);
    }

    fd_set basefds, readfds;
    FD_ZERO(&basefds);
    FD_SET(STDIN_FILENO, &basefds);
    FD_SET(sock_fd, &basefds);

    char buf[1024] = {0};

    while (1) {
        FD_ZERO(&readfds);
        memcpy(&readfds, &basefds, sizeof(readfds));

        int ret_select;
        do {
            ret_select = select(sock_fd + 1, &readfds, NULL, NULL, NULL);
        } while (ret_select < 0 && errno == EINTR);

        if (FD_ISSET(sock_fd, &readfds)) {
            bzero(buf, sizeof(buf));
            int ret_recv = recv(sock_fd, buf, sizeof(buf), 0);
            if (ret_recv == 0) {
                printf("server is broken\n");
                break;
            }
            int ret_write = write(STDOUT_FILENO, buf, ret_recv);
        }
        if (FD_ISSET(STDIN_FILENO, &readfds)) {
            bzero(buf, sizeof(buf));
            int ret_read = read(STDIN_FILENO, buf, sizeof(buf));
            int ret_send = send(sock_fd, buf, ret_read, 0);
        }
    }
}
