#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <sys/socket.h>
#include "sys_header.h"

int main(int argc, char** argv) {
    if (argc < 3 || argc > 3) {
        fprintf(stderr, "usage: exec ip port\n");
        return -1;
    }
    // 使用udp无连接
    int sock_fd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock_fd < 0) {
        perror("socket");
        return -1;
    }

    struct sockaddr_in addr_in = {.sin_family = AF_INET,
                                  .sin_addr.s_addr = inet_addr(argv[1]),
                                  .sin_port = htons(atoi(argv[2]))};

    // 发送数据
    int ret_send_to = sendto(sock_fd, "Hello", 5, 0, (struct sockaddr*)&addr_in, sizeof(addr_in));
    if (ret_send_to < 0) {
        perror("sendto");
        return -1;
    }

    // 接收服务器的数据
    char buf[1024] = {0};
    int ret_recv_from = recvfrom(sock_fd, buf, sizeof(buf), 0, NULL, NULL);
    if (ret_recv_from < 0) {
        perror("recv");
        return -1;
    }

    printf("buf is %s\n", buf);

    return 0;
}
