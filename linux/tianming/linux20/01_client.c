/****************************************************
 * @file    01_client.c
 * @brief   客户端
 * @author  bitofux
 * @date    2025-10-10
 ****************************************************/
#include <stdint.h>
#include <strings.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>

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

    if (connect(sock_fd, (const struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        exit(-1);
    }

    char buf[21] = {0};
    int ret_read = read(STDIN_FILENO, buf, sizeof(buf));
    if (ret_read > 20) {
        fprintf(stderr, "输入过长\n");
        exit(-1);
    }
    buf[ret_read - 1] = '\0';
    // 打开这个文件
    int file_fd = open(buf, O_RDWR | O_CREAT, 0644);
    printf("buf is %s\n", buf);
    int ret_send = send(sock_fd, buf, ret_read - 1, 0);
    printf("ret_read is %d\n", ret_read);

    char buffer[2] = {0};
    while (1) {
        bzero(buffer, sizeof(buffer));
        // 读取sock_fd接收来的数据
        int nums = recv(sock_fd, buffer, sizeof(buffer), MSG_DONTWAIT);
        if (nums < 0) {  // 这里你设置的是非阻塞
            // 可能服务端还没发送数据,你这边直接读取
            // 发现没有数据,直接返回-1,写的是break结束掉这个循环
            // 当服务端发送的时候,你已经读取不了的
            // 因此应该是continue
            // printf("读取完毕\n");
            continue;
        } else if (nums == 0) {
            // printf("对端关闭\n");
            break;
        }
        // 将读取到的数据写入到文件里去
        (void)write(file_fd, buffer, nums);
    }
    close(file_fd);
    close(sock_fd);
}
