#include <arpa/inet.h>
#include <error.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include "sys_header.h"

// 自定义协议去发送数据 小火车头
// 前面4个字节保存后续数据的大小
// 后面是具体的数据
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
    int len = strlen(file_name);
    char buf[100] = {0};
    int file_fd = open(file_name, O_RDONLY);
    int ret_read = read(file_fd, buf, sizeof(buf));
    if (ret_read < 0) {
        perror("read");
        return -1;
    }
    int size = ret_read;
    printf("size is %d\n",size);

    // 先发送头部数据 -- 表示后续数据所占的字节
    int one_send_head = send(sock_fd, &len, sizeof(int), 0);
    if (one_send_head < 0) {
        perror("send");
        return -1;
    }
    // 再发送具体数据
    int one_send_data = send(sock_fd, file_name, strlen(file_name), 0);
    if (one_send_data < 0) {
        perror("send");
        return -1;
    }
    // error(1, errno, "send");
    // 先发送头部数据 -- 表示后续数据所占的字节
    int two_send_head = send(sock_fd, &size, sizeof(int), 0);
    if (two_send_head < 0) {
        perror("send");
        return -1;
    }
    int two_send_data = send(sock_fd, buf, size, 0);
    if (two_send_data < 0) {
        perror("send");
        return -1;
    }
    // error(1, errno, "send");

    while (1);
}
