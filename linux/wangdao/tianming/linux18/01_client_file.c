#include <arpa/inet.h>
#include <error.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include "sys_header.h"

int main(int argc, char** argv) {
    if (argc < 3 || argc > 3) {
        fprintf(stderr, "usage:exec ip port\n");
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

    int ret_conn = connect(sock_fd, (struct sockaddr*)&addr_in, sizeof(addr_in));
    if (ret_conn < 0) {
        perror("connect");
        return -1;
    }
    // error(1, errno, "connect");

    const char* file_name = "1.txt";
    char buf[100] = {0};
    int file_fd = open(file_name, O_RDONLY);
    int ret_read = read(file_fd, buf, sizeof(buf));

    // 将文件名发送到服务器
    int one_send = send(sock_fd, file_name, strlen(file_name), 0);
    if (one_send < 0) {
        perror("send");
        return -1;
    }
    // error(1, errno, "send");
    // 将文件内容发送到服务器
    int two_send = send(sock_fd, buf, ret_read, 0);
    if (two_send < 0) {
        perror("send");
        return -1;
    }
    // error(1, errno, "send");

    while (1);
}
