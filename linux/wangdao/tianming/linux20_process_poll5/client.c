/****************************************************
 * @file    client.c
 * @brief   客户端
 * @author  bitofux
 * @date    2025-10-24
 ****************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <strings.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/epoll.h>
#include <errno.h>
#include <sys/uio.h>

int main(int argc, char** argv) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    (void)inet_pton(AF_INET, argv[1], &server_addr.sin_addr);
    int ret_conn = connect(sock, (const struct sockaddr*)&server_addr, sizeof(server_addr));

    send(sock, "Hello", 5, 0);

    char buf[20] = {0};
    recv(sock, buf, sizeof(buf), 0);

    printf("buf: %s\n", buf);

    while (1) {
    }
    return 0;
}
