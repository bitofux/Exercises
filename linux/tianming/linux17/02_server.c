#include <arpa/inet.h>
#include <error.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
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

    int ret_bind = bind(sock_fd, (struct sockaddr*)&addr_in, sizeof(addr_in));
    if (ret_bind < 0) {
        perror("bind");
        return -1;
    }

    int ret_listen = listen(sock_fd, 64);
    if (ret_listen < 0) {
        perror("listen");
        return -1;
    }

    int new_fd = accept(sock_fd, NULL, NULL);
    if (new_fd < 0) {
        perror("accept");
        return -1;
    }

    char buf[64] = {0};
    while (1) {
        (void)memset(buf, 0, sizeof(buf));
        int ret_recv = recv(new_fd, buf, sizeof(buf), 0);
        if (ret_recv < 0) {
            perror("recv");
            return -1;
        }
        fprintf(stdout, "%s\n", buf);
        (void)memset(buf, 0, sizeof(buf));
        int ret_read = read(STDIN_FILENO, buf, sizeof(buf));
        if (ret_read < 0) {
            perror("read");
            return -1;
        }

        int ret_send = send(new_fd, buf, sizeof(buf), 0);
        if (ret_send < 0) {
            perror("send");
            return -1;
        }
    }

    close(sock_fd);
    close(new_fd);
    return 0;
}
