/****************************************************
 * @file    one_peocess_poll.c
 * @brief   线程池第一版本
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
    // 1. 创建本地socketpair对象
    int sp[2] = {0};
    int socket_pair = socketpair(AF_LOCAL, SOCK_STREAM, 0, sp);
    if (socket_pair < 0) {
        perror("socketpair");
        return -1;
    }

    // 创建进程池 -> 先创建5个进程
    for (int i = 0; i < 5; i++) {
        int pid = fork();
        if (pid == 0) {
            // 这是子进程
            // 先关闭一个本地socket对象
            close(sp[0]);
            // 完成任务
            while (1) {
                // 读取父进程发送过来的数据并处理
                // 处理完成之后通知父进程
                struct msghdr msg;
                memset(&msg, 0, sizeof(msg));

                char ch;
                struct iovec iov = {0};
                iov.iov_base = &ch;
                iov.iov_len = sizeof(char);

                char control[CMSG_SPACE(sizeof(int))] = {0};

                msg.msg_name = NULL;
                msg.msg_namelen = 0;
                msg.msg_iov = &iov;
                msg.msg_iovlen = 1;
                msg.msg_control = control;
                msg.msg_controllen = CMSG_SPACE(sizeof(int));
                printf("i am child,my pid is %d\n", getpid());
                size_t n = recvmsg(sp[1], &msg, 0);
                if (n < 0) {
                    perror("recvmsg");
                    return -1;
                }
                printf("i am child, i read data! my pid is %d\n", getpid());
                // 获取第一个控制消息的起始地址
                struct cmsghdr* cmsg = CMSG_FIRSTHDR(&msg);
                // 获取数据区的地址
                int* data = (int*)CMSG_DATA(cmsg);

                char buffer[1024] = {0};
                printf("i am child,my pid is %d\n", getpid());
                size_t ret_recv = recv(*data, buffer, sizeof(buffer), 0);
                printf("i am child,i send data now.buffer: %s\n", buffer);
                size_t ret_send = send(*data, "NiHao!", 6, 0);
                // 处理完成之后，发送给父进程
                send(sp[1], "done", 4, 0);
            }
        }
    }
    close(sp[1]);
    // 父进程逻辑,子进程一直在while死循环中

    // 创建一个用于建立的socket对象
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        return -1;
    }
    // 绑定ip + port
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    (void)inet_pton(AF_INET, argv[1], &server_addr.sin_addr);

    // 处理TIME_WAIT的情况，并未实际解决
    // 只是让端口可复用
    int reuse = 1;
    (void)setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse));
    int ret_bind = bind(sock, (const struct sockaddr*)&server_addr, sizeof(server_addr));
    if (ret_bind < 0) {
        perror("bind");
        return -1;
    }
    int ret_listen = listen(sock, 64);
    if (ret_listen < 0) {
        perror("listen");
        return -1;
    }

    // 用户态的缓冲区
    char buf[1024] = {0};

    // 监听本地的socket对象与用于建立连接的socket

    // 创建一个epoll实例
    int ep = epoll_create1(EPOLL_CLOEXEC);
    if (ep < 0) {
        perror("epoll_create1");
        return -1;
    }
    struct epoll_event event = {.data.fd = sock, .events = EPOLLIN};
    (void)epoll_ctl(ep, EPOLL_CTL_ADD, sock, &event);
    event.data.fd = sp[0];
    (void)epoll_ctl(ep, EPOLL_CTL_ADD, sp[0], &event);

    // 存放已就绪的数组
    struct epoll_event events[2] = {0};

    while (1) {
        int nums = epoll_wait(ep, events, 2, -1);
        for (int i = 0; i < nums; ++i) {
            int fd = events[i].data.fd;
            if (fd == sock) {
                int ret_accept = 0;
                do {
                    ret_accept = accept(sock, NULL, NULL);
                } while (ret_accept < 0 && errno == EINTR);
                // 将文件描述符发送到子进程
                struct msghdr msg;
                memset(&msg, 0, sizeof(msg));

                msg.msg_name = NULL;
                msg.msg_namelen = 0;

                // 普通数据部分
                char ch = 'w';
                struct iovec iov = {.iov_base = &ch, .iov_len = sizeof(char)};
                msg.msg_iov = &iov;
                msg.msg_iovlen = 1;

                // 控制信息(文件描述符)
                // 我们只需要携带一条控制信息
                // 因此我们只需要构建一块控制信息所需的
                // 内存空间即可
                // 一个文件描述符所需要的控制信息的内存
                // 大小，含对齐
                size_t rights = CMSG_SPACE(sizeof(int));
                // 利用获取到的内存大小构建控制消息缓冲区
                char control[rights];
                memset(control, 0, rights);
                msg.msg_control = control;
                msg.msg_controllen = rights;

                // 获取第一个控制消息的起始地址,
                // 开始构建第一个控制消息
                struct cmsghdr* cmsg = CMSG_FIRSTHDR(&msg);
                cmsg->cmsg_level = SOL_SOCKET;
                cmsg->cmsg_type = SCM_RIGHTS;
                cmsg->cmsg_len = CMSG_LEN(sizeof(int));

                // 获取第一条控制消息中的数据区域
                int* cmsg_data = (int*)CMSG_DATA(cmsg);
                *cmsg_data = ret_accept;
                size_t n = sendmsg(sp[0], &msg, 0);
                if (n < 0) {
                    perror("sendmsg");
                    return -1;
                }
                continue;
            } else {
                bzero(buf, sizeof(buf));
                recv(sp[0], buf, sizeof(buf), 0);
                printf("%s\n", buf);
            }
        }
    }
}
