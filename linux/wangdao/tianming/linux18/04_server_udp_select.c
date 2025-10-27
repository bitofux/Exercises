#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <sys/epoll.h>
#include <sys/socket.h>
#include "sys_header.h"

typedef enum { ALIVE, DEAD } sta_t;
typedef struct {
    sta_t status;
    struct sockaddr_in client_addr;
} conn_t;
conn_t conn_array[20] = {0};
int size = 0;
int main(int argc, char** argv) {
    if (argc < 3 || argc > 3) {
        fprintf(stderr, "usage:exec ip port\n");
        return -1;
    }
    int sock_fd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock_fd < 0) {
        perror("socket");
        return -1;
    }
    struct sockaddr_in server_addr = {.sin_family = AF_INET,
                                      .sin_addr.s_addr = inet_addr(argv[1]),
                                      .sin_port = htons(atoi(argv[2]))};

    int ret_bind = bind(sock_fd, (struct sockaddr*)&server_addr, sizeof(server_addr));
    if (ret_bind < 0) {
        perror("bind");
        return -1;
    }
    int ep_fd = epoll_create1(EPOLL_CLOEXEC);
    if (ep_fd < 0) {
        perror("epoll_create1");
        return -1;
    }
    struct epoll_event event = {.events = EPOLLIN, .data.fd = sock_fd};
    epoll_ctl(ep_fd, EPOLL_CTL_ADD, sock_fd, &event);
    struct sockaddr_in client_addr;
    char buf[1024] = {0};
    socklen_t client_len = sizeof(client_addr);
    struct epoll_event events[1] = {0};
    bool flag = true;
    while (1) {
        bzero(&client_addr, client_len);
        bzero(events, sizeof(events));
        bzero(buf, sizeof(buf));
        int epoll_num = epoll_wait(ep_fd, events, 1, -1);
        if (epoll_num < 0) {
            perror("epoll_wait");
            return -1;
        }
        ++size;
        int ret_recv_from =
            recvfrom(sock_fd, buf, sizeof(buf), 0, (struct sockaddr*)&client_addr, &client_len);
        if (ret_recv_from < 0) {
            perror("recvfrom");
            return -1;
        }
        for (int i = 0; i < size; ++i) {
            if (ntohs(conn_array[i].client_addr.sin_port) == ntohs(client_addr.sin_port)) {
                flag = false;
                --size;
            }
        }
        if (flag == true) {
            conn_array[size - 1].status = ALIVE;
            conn_array[size - 1].client_addr = client_addr;
        }
        for (int i = 0; i < size; ++i) {
            if (conn_array[i].status == ALIVE &&
                (ntohs(conn_array[i].client_addr.sin_port) != ntohs(client_addr.sin_port))) {
                int ret_send_to = sendto(sock_fd, buf, ret_recv_from, 0,
                                         (struct sockaddr*)&conn_array[i].client_addr,
                                         sizeof(conn_array[i].client_addr));
                if (ret_send_to < 0) {
                    perror("sendto");
                    return -1;
                }
            }
        }
    }
}
