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
#include <time.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/epoll.h>
#include <arpa/inet.h>
#include <netinet/in.h>

double timespec_diff_ms(struct timespec* start, struct timespec* end) {
    return (end->tv_sec - start->tv_sec) * 1000.0 + (end->tv_nsec - start->tv_nsec) / 1e6;
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
    printf("file_size: %ld\n", file_size);
    // 创建并打开这个文件
    int fd = open(file_name, O_RDWR | O_CREAT, 0644);
    if (fd < 0) {
        perror("open");
        return -1;
    }
    // 读取文件对象的接收缓冲区
    // 将数据写入到文件
    char buf[1000] = {0};
    // 每次读取数据大小
    int file_content_size = 0;
    struct timespec start;
    clock_gettime(CLOCK_MONOTONIC, &start);
    // 1000ms内接收的文件数据大小
    long one_1000_data = 0;
    // 记录接收的数据总数
    long access_data = 0;
    int count = 0;
    while (1) {
        int ret_recv = recv(sock_fd, &file_content_size, sizeof(int), MSG_WAITALL);
        if (ret_recv < 0) {
            perror("recv");
            return -1;
        } else if (ret_recv == 0) {
            break;
        }
        ret_recv = recv(sock_fd, buf, file_content_size, MSG_WAITALL);
        if (ret_recv < 0) {
            perror("recv");
            return -1;
        } else if (ret_recv == 0) {
            break;
        }
        // 每次循环计算接收数据的总和
        one_1000_data += file_content_size;
        access_data += file_content_size;
        struct timespec end;
        clock_gettime(CLOCK_MONOTONIC, &end);
        // 计算50ms内接收字节数据个数
        // 并根据数据个数与事件,计算大概每秒
        // 的接收速率 mb/s
        if (timespec_diff_ms(&start, &end) > 100.0) {
            long mb = one_1000_data / 1024 / 1024;
            printf("%.2lf%%,%ldmb/s\n", ((double)access_data / file_size) * 100, 10 * mb);
            fflush(stdout);
            start = end;
            one_1000_data = 0;
        }
        if (access_data == file_size) {
            printf("%.2lf%%\n", ((double)access_data / file_size) * 100);
        }
        // 将读取到的数据写入文本文件
        int ret_write = write(fd, buf, file_content_size);
        if (ret_write < 0) {
            perror("write");
            return -1;
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
