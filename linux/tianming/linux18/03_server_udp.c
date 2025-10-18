#include <arpa/inet.h>
#include <complex.h>
#include <netinet/in.h>
#include <stdio.h>
#include <sys/socket.h>
#include "sys_header.h"

int main(int argc, char** argv) {
    if (argc < 3 || argc > 3) {
        fprintf(stderr, "usage: exec ip port\n");
        return -1;
    }

    // 使用udp -- 面向无连接
    int sock_fd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock_fd < 0) {
        perror("socket");
        return -1;
    }

    struct sockaddr_in addr_in = {.sin_family = AF_INET,
                                  .sin_addr.s_addr = inet_addr(argv[1]),
                                  .sin_port = htons(atoi(argv[2]))};

    int ret_bind = bind(sock_fd, (struct sockaddr*)&addr_in, sizeof(addr_in));
    if (ret_bind < 0) {
        perror("bind");
        return -1;
    }

    // 保存客户端的信息 因为后续发送数据需要知道具体是哪个客户端
    char buf[1024] = {0};
    struct sockaddr_in addr_in_client;
    socklen_t len = sizeof(addr_in_client);
    int ret_recv_from =
        recvfrom(sock_fd, buf, sizeof(buf), 0, (struct sockaddr*)&addr_in_client, &len);
    if (ret_recv_from < 0) {
        perror("recvfrom");
        return -1;
    }
    printf("buf is %s\n", buf);

    int ret_send_to =
        sendto(sock_fd, "nihao", 5, 0, (struct sockaddr*)&addr_in_client, sizeof(addr_in_client));
    if (ret_send_to < 0) {
        perror("sendto");
        return -1;
    }
    return EXIT_SUCCESS;
}
