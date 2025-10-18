/****************************************************
 * @file    03_server.c
 * @brief   服务器设置文件描述符阻塞
 *          读取客户端发送的100字节
 *          每次读取20个字节，查看读取完之后
 *          recv是否阻塞,设置非阻塞之后呢
 *          epoll lt模式下是否再次通知? et呢?
 * @author  bitofux
 * @date    2025-10-10
 ****************************************************/
#include <fcntl.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <sys/socket.h>
#include <unistd.h>
#include <sys/epoll.h>
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

    if (bind(sock_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        exit(-1);
    }

    if (listen(sock_fd, 64) < 0) {
        perror("listen");
        exit(-1);
    }

    int net_fd = accept(sock_fd, NULL, NULL);
    printf("accept\n");
#if 0
    char buf[21] = {0};
    // 读取数据
    for (int i = 0; i < 5; ++i) {
        int ret_recv = recv(net_fd, buf, sizeof(buf), 0);
        buf[ret_recv] = '\0';
        printf("buf is %s\n,ret_recv is %d\n", buf, ret_recv);
    }
    printf("5次读取完毕,再次调用recv查看现象(文件描述符默认是阻塞状态)\n");
    int ret_recv = recv(net_fd, buf, sizeof(buf), 0);
    printf("ret_recv is %d\n", ret_recv);
#endif

#if 0
    // 将这个文件描述符设置为非阻塞
    printf("非阻塞模式下,还是一样的代码\n");
    int flag = fcntl(net_fd, F_GETFL, 0);
    if (fcntl(net_fd, F_SETFL, flag | O_NONBLOCK) < 0) {
        perror("fcntl");
        exit(-1);
    }
    char buf[21] = {0};
    // 读取数据
    for (int i = 0; i < 5; ++i) {
        int ret_recv = recv(net_fd, buf, sizeof(buf), 0);
        buf[ret_recv] = '\0';
        printf("buf is %s\n,ret_recv is %d\n", buf, ret_recv);
    }
    printf("5次读取完毕,再次调用recv查看现象(文件描述符号现在是非阻塞状态)\n");
    int ret_recv = recv(net_fd, buf, sizeof(buf), 0);
    printf("ret_recv is %d\n", ret_recv);
#endif
#if 0
    // 测试epoll的lt(默认)
    // 当这个文件描述符对应的文件对象中的接收缓冲区
    // 还有数据，那么epoll_wait在lt模式下就会一直就绪
    // recv在阻塞模式下就可以读写不会阻塞
    int ep_fd = epoll_create1(EPOLL_CLOEXEC);
    if (ep_fd < 0) {
        perror("epoll_create1");
        exit(-1);
    }
    struct epoll_event event = {.data.fd = net_fd, .events = EPOLLIN};
    epoll_ctl(ep_fd, EPOLL_CTL_ADD, net_fd, &event);
    struct epoll_event events[1];
    char buf[20] = {0};
    while (1) {
        bzero(events, sizeof(events));
        printf("before epoll_wait\n");
        int ready_num = epoll_wait(ep_fd, events, 1, -1);
        printf("after epoll_wait\n");

        int fd = events[0].data.fd;

        int ret_recv = recv(fd, buf, sizeof(buf), 0);  // 阻塞模式
        for (int i = 0; i < 20; ++i) {
            printf("%c", buf[i]);
        }
        printf("\n");
    }
#endif
    // ET模式下,如果一次就绪未读完数据，epoll_wait
    // 不会就绪,直到下次状态改变(来新的数据或者由空变有)
    // 所以在et模式下,你需要一次就绪就将数据全部读出来,
    // 防止旧的数据一直在 新的数据读不到
    // EGAIN -1
    int ep_fd = epoll_create1(EPOLL_CLOEXEC);
    if (ep_fd < 0) {
        perror("epoll_create1");
        exit(-1);
    }
    struct epoll_event event = {.data.fd = net_fd, .events = EPOLLIN | EPOLLET};
    epoll_ctl(ep_fd, EPOLL_CTL_ADD, net_fd, &event);
    struct epoll_event events[1];
    char buf[20] = {0};
    while (1) {
        bzero(events, sizeof(events));
        printf("before epoll_wait\n");
        int ready_num = epoll_wait(ep_fd, events, 1, -1);
        printf("after epoll_wait\n");

        int fd = events[0].data.fd;

        int ret_recv = recv(fd, buf, sizeof(buf), 0);  // 阻塞模式
        for (int i = 0; i < 20; ++i) {
            printf("%c", buf[i]);
        }
        printf("\n");
    }
    return 0;
}
