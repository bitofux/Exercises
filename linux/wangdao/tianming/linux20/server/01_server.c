/****************************************************
 * @file    01_server.c
 * @brief   服务端
 * @author  bitofux
 * @date    2025-10-10
 ****************************************************/
#include <stdint.h>
#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

int main() {
    const char* ip = "10.211.55.5";
    uint16_t port = 8080;

    int sock_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sock_fd < 0) {
        perror("socket");
        exit(-1);
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    (void)inet_pton(AF_INET, ip, &server_addr.sin_addr);

    int reuse = 1;
    (void)setsockopt(sock_fd, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse));

    if (bind(sock_fd, (const struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        exit(-1);
    }

    if (listen(sock_fd, 64) < 0) {
        perror("listen");
        exit(-1);
    }

    int net_fd = accept(sock_fd, NULL, NULL);

    char buf_file[21] = {0};
    int ret_recv = recv(net_fd, buf_file, sizeof(buf_file), 0);
    printf("ret_recv is %d\n", ret_recv);
    if (ret_recv > 20) {
        fprintf(stderr, "读取失败\n");
        exit(-1);
    }
    buf_file[ret_recv] = '\0';
    printf("buf_file is %s\n", buf_file);

    // 打开当前目录遍历目录项
    DIR* dir = opendir(".");
    if (dir == NULL) {
        perror("opendir");
        exit(-1);
    }

    struct dirent* field = readdir(dir);
    while (field != NULL) {
        if (strcmp(field->d_name, buf_file) == 0) {
            printf("%s\n", field->d_name);
            char file_name[20] = {0};
            strcat(file_name, "./");
            strcat(file_name, field->d_name);
            printf("file_name is %s\n", file_name);
            // 打开当前这个文件
            int file_fd = open(file_name, O_RDWR);
            // 循环读取当前文件
            char buf[10] = {0};
            while (1) {
                bzero(buf, sizeof(buf));
                int ret_read = read(file_fd, buf, sizeof(buf));
                if (ret_read == 0) {
                    printf("读取完毕\n");
                    break;
                }
                (void)send(net_fd, buf, ret_read, 0);
            }
        }
        field = readdir(dir);
    }
    printf("文件不存在\n");
    return 0;
}
