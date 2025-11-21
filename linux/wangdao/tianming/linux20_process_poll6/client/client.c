/****************************************************
 * @file    client.c
 * @brief   测试客户端
 * @author  bitofux
 * @date    2025-10-28
 ****************************************************/
#define _POSIX_C_SOURCE 199309L
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/epoll.h>
#include <arpa/inet.h>
#include <netinet/in.h>
ssize_t recv_n(int fd, void* buf, size_t len) {
    off_t received = 0;
    while (received < len) {
        size_t n = recv(fd, (char*)buf + received, len - received, 0);
        if (n <= 0) return n;
        received += n;
    }
    return received;
}
int work(int sock_fd) {
    // 接收文件名大小
    size_t file_name_length;
    int ret_recv = recv(sock_fd, &file_name_length, sizeof(size_t), MSG_WAITALL);
    if (ret_recv < 0) {
        perror("recv");
        return -1;
    }
    char file_name[file_name_length + 1];
    // 接收文件名称
    ret_recv = recv(sock_fd, file_name, file_name_length, MSG_WAITALL);
    if (ret_recv < 0) {
        perror("recv");
        return -1;
    }
    file_name[ret_recv] = '\0';
    // 接收文件大小
    off_t file_size = 0;
    ret_recv = recv(sock_fd, &file_size, sizeof(off_t), MSG_WAITALL);
    // 创建并打开这个文件
    int fd = open(file_name, O_RDWR | O_CREAT, 0644);
    if (fd < 0) {
        perror("open");
        return -1;
    }
    // 读取文件对象的接收缓冲区
    // 将数据写入到文件
    char buf[1024] = {0};
    off_t access_total = 0;
    while (access_total < file_size) {
        ssize_t ret_recv = recv_n(sock_fd, buf, 1024);
        if (ret_recv < 0) {
            fprintf(stderr, "recv_n is failed\n");
        } else {
            ssize_t ret_write = write(fd, buf, ret_recv);
            if (ret_write < 0) {
                perror("write");
            }
            access_total += ret_recv;
        }
    }
    return 0;
}

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

    // 数据处理
    if (work(sock_fd) < 0) {
        fprintf(stderr, "work failed\n");
    }
}
