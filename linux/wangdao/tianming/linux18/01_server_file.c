#include <stdio.h>
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
    // error(1, errno, "socket");

    struct sockaddr_in addr_in = {.sin_family = AF_INET,
                                  .sin_port = htons(atoi(argv[2])),
                                  .sin_addr.s_addr = inet_addr(argv[1])};

    int ret_bind = bind(sock_fd, (struct sockaddr*)&addr_in, sizeof(addr_in));
    if (ret_bind < 0) {
        perror("bind");
        return -1;
    }
    // error(1, errno, "bind");

    int ret_listen = listen(sock_fd, 64);
    if (ret_listen < 0) {
        perror("listen");
        return -1;
    }
    // error(1, errno, "listen");

    int net_fd = accept(sock_fd, NULL, NULL);
    if (net_fd < 0) {
        perror("accept");
        return -1;
    }
    // error(1, errno, "accept");

    char buf[100] = {0};
    int ret_recv = recv(net_fd, buf, sizeof(buf), 0);
    printf("%s\n", buf);

    while (1);
}
