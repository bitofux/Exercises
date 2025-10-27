/****************************************************
 * @file    01_client_select.c
 * @brief   使用select客户端监听键盘输入和用于与服务器通信的
 *          sockfd
 * @author  bitofux
 * @date    2025-10-05
 ****************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <strings.h>
#include <unistd.h>

#include <sys/select.h>  // for select
#include <sys/socket.h>  //for socket
#include <netinet/in.h>  //for struct sockaddr_in
#include <arpa/inet.h>   //for inet_addr inet_aton
#include <errno.h>
int main(int argc, char** argv) {
    if (argc < 3 || argc > 3) {
        fprintf(stderr, "usage: exec ip port\n");
        exit(-1);
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (-1 == sockfd) {
        perror("sockfd");
        exit(-1);
    }

    struct sockaddr_in server_addr = {.sin_family = AF_INET,
                                      .sin_port = htons(atoi(argv[2])),
                                      .sin_addr.s_addr = inet_addr(argv[1])};

    int ret_conn = connect(sockfd, (const struct sockaddr*)&server_addr, sizeof(server_addr));
    if (ret_conn < 0) {
        perror("connect");
        exit(-1);
    }

    char buf[1024] = {0};
    fd_set readfds, basefds;
    FD_ZERO(&basefds);

    FD_SET(sockfd, &basefds);
    FD_SET(STDIN_FILENO, &basefds);

    while (1) {
        bzero(&readfds, sizeof(readfds));
        // 每次都要重置监听集合
        memcpy(&readfds, &basefds, sizeof(basefds));

        int ret_select = 0;
        do {
            ret_select = select(sockfd + 1, &readfds, NULL, NULL, NULL);
        } while (ret_select < 0 && errno == EINTR);  // 若返回-1且是被信号中断，则重试

        if (FD_ISSET(sockfd, &readfds)) {
            bzero(buf, sizeof(buf));
            int ret_recv = recv(sockfd, buf, sizeof(buf), 0);
            if (ret_recv < 0) {
                perror("recv");
                exit(-1);
            } else if (ret_recv == 0) {
                printf("server is broken\n");
                break;
            }
            printf("server: %s", buf);
        }
        if (FD_ISSET(STDIN_FILENO, &readfds)) {
            bzero(buf, sizeof(buf));
            int ret_read = read(STDIN_FILENO, buf, sizeof(buf));
            if (ret_read < 0) {
                perror("read");
                exit(-1);
            }
            int ret_send = send(sockfd, buf, ret_read, 0);
            if (ret_send < 0) {
                perror("send");
                exit(-1);
            }
        }
    }
}
