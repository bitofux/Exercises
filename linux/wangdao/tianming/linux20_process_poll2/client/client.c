/****************************************************
 * @file    client.c
 * @brief   测试客户端
 * @author  bitofux
 * @date    2025-10-28
 ****************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/epoll.h>
#include <arpa/inet.h>
#include <netinet/in.h>

int work(int sock_fd) {
    // 接收文件名大小
    size_t file_name_length;
    int ret_recv = recv(sock_fd, &file_name_length, sizeof(size_t), 0);
    if (ret_recv < 0) {
        perror("recv");
        return -1;
    }
    char file_name[file_name_length + 1];
    // 接收文件名称
    ret_recv = recv(sock_fd, file_name, file_name_length, 0);
    if (ret_recv < 0) {
        perror("recv");
        return -1;
    }
    file_name[ret_recv] = '\0';

    // 创建并打开这个文件
    int fd = open(file_name, O_RDWR | O_CREAT, 0644);
    if (fd < 0) {
        perror("open");
        return -1;
    }
    // 读取文件内容大小
    int file_content_size;
    ret_recv = recv(sock_fd, &file_content_size, sizeof(int), 0);
    if (ret_recv < 0) {
        perror("recv");
        return -1;
    }
    char file_content[file_content_size + 1];
    // 读取文件实际内容
    ret_recv = recv(sock_fd, file_content, file_content_size, 0);
    file_content[ret_recv] = '\0';
    // 将读取到的内容写入到新打开的文件中
    write(fd, file_content, sizeof(file_content) - 1);
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
