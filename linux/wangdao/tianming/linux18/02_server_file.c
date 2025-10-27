#include <fcntl.h>
#include <stdio.h>
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


    // 读取文件名
    char file_name[64] = {0};
    int file_name_size = 0;
    int one_recv_size = recv(net_fd, &file_name_size, sizeof(int), 0);
    if (one_recv_size < 0) {
        perror("recv");
        return -1;
    }
    int one_recv_data = recv(net_fd, file_name, file_name_size, 0);
    file_name[file_name_size] = '\0';

    // 创建一个文件
    int file_fd = open(file_name, O_RDWR | O_CREAT,0644);

    char data[100] = {0};
    int data_size = 0;
    // 读取文件数据
    int two_recv_size = recv(net_fd, &data_size, sizeof(int), 0);
    if (two_recv_size < 0) {
        perror("recv");
        return -1;
    }
    int two_recv_data = recv(net_fd, data, data_size, 0);
    if (two_recv_data < 0) {
        perror("recv");
        return -1;
    }

    // 将数据写到新建的文件中
    int ret_write = write(file_fd, data, two_recv_size);
    if (ret_write < 0) {
        perror("write");
        return -1;
    }

    while (1);
}
