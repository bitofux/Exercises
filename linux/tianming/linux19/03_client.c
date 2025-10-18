/****************************************************
 * @file    03_client.c
 * @brief   简单的客户端程序:
 *              只发送100字节数据到服务器测试
 *              服务器阻塞读取
 * @author  bitofux
 * @date    2025-10-10
 ****************************************************/
#include <setjmp.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <time.h>
#include <unistd.h>
#include <sys/epoll.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <errno.h>

int main() {
    const char* ip = "10.211.55.5";
    uint16_t port = 8080;

    int sock_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sock_fd == -1) {
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

    char buf[100] = {0};
    memset(buf, 'a', sizeof(buf));

    // 发送100字节
    (void)send(sock_fd, buf, sizeof(buf), 0);

    sleep(5);
    // 测试et，再次发送20个字节数据
    (void)send(sock_fd, "nihaonihaonihaonihao", 20, 0);
    // epoll_wait会返回，但是服务端读取的还是之前的旧数据
    // 新发送的数据读不到暂时
    while (1);
}
