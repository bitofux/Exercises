#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <unistd.h>
#include "sys_header.h"

int main(int argc, char** argv) {
    if (argc < 3 || argc > 3) {
        fprintf(stderr, "usage:exec ip port\n");
        return -1;
    }
    int sock_fd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock_fd < 0) {
        perror("socket");
        return -1;
    }

    struct sockaddr_in server_addr = {.sin_family = AF_INET,
                                      .sin_addr.s_addr = inet_addr(argv[1]),
                                      .sin_port = htons(atoi(argv[2]))};

    char buf[1024] = {0};
    fd_set readfds, base_fds;
    FD_ZERO(&base_fds);
    FD_SET(sock_fd, &base_fds);
    FD_SET(STDIN_FILENO, &base_fds);

    while (1) {
        FD_ZERO(&readfds);
        memcpy(&readfds, &base_fds, sizeof(base_fds));
        int ret_select = select(sock_fd + 1, &readfds, NULL, NULL, NULL);
        if (ret_select < 0) {
            perror("select");
            return -1;
        }
        if (FD_ISSET(STDIN_FILENO, &readfds)) {
            bzero(buf, sizeof(buf));
            int ret_read = read(STDIN_FILENO, buf, sizeof(buf));
            if (ret_read < 0) {
                perror("read");
                return -1;
            }
            int ret_send_to = sendto(sock_fd, buf, ret_read, 0, (struct sockaddr*)&server_addr,
                                     sizeof(server_addr));
            if (ret_send_to < 0) {
                perror("sendto");
                return -1;
            }
        }
        if (FD_ISSET(sock_fd, &readfds)) {
            bzero(buf, sizeof(buf));
            printf("就绪了吗?\n");
            int ret_recv_from = recvfrom(sock_fd, buf, sizeof(buf), 0, NULL, NULL);
            if (ret_recv_from < 0) {
                perror("recvfrom");
                return -1;
            }
            printf("server->buf:%s", buf);
        }
    }
}
