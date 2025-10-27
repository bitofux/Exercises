#include <stdio.h>
#include "sys_header.h"
int main(int argc, char** argv) {
    if (argc < 3) {
        fprintf(stderr, "usage: exec ip port\n");
        return -1;
    }

    // 创建一个socket类型的文件对象
    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd < 0) {
        error(1, errno, "socket");
    }

    // 用户态创建一个用于保存ip和端口
    // 的对象,用于传给内核态
    struct sockaddr_in addr_in;
    // 地址类型
    addr_in.sin_family = AF_INET;
    // 大端表示法的端口
    addr_in.sin_port = htons(atoi(argv[2]));
    // 大端表示法的ip地址
    addr_in.sin_addr.s_addr = inet_addr(argv[1]);

    // 绑定地址+端口
    int ret_bind = bind(sock_fd, (struct sockaddr*)&addr_in, sizeof(addr_in));
    if (ret_bind < 0) {
        error(1, errno, "bind");
    }

    // 开启对这个socket文件对象的监听
    // 将socket对应的接收队列和发送队列改变为
    // 接收了客户端发送的带有syn的报文的队列和
    // 成功三次握手,也就是接收到了客户端发送的ack
    // 的队列，一个叫半连接队列 一个是全连接队列
    int ret_listen = listen(sock_fd, 64);
    if (ret_listen < 0) {
        error(1, errno, "listen");
    }

    // 当全连接队列有数据来的时候,代表与一个客户端建立
    // 了三次握手,将其从全连接取出,并新创建一个socket
    // 文件对象用于与客户端进行通信
    // 无数据的时候,accept会阻塞当前进程或线程
    // net_fd是当前取出来的一个全连接所建立的文件对象
    // 对应的文件描述符
    int net_fd = accept(sock_fd, NULL, NULL);
    if (net_fd < 0) {
        error(1, errno, "accept");
    }

    fd_set readfds;

    char buf[1024] = {0};

    while (1) {
        FD_ZERO(&readfds);
        FD_SET(STDIN_FILENO, &readfds);
        FD_SET(net_fd, &readfds);
        int ret_select = select(net_fd + 1, &readfds, NULL, NULL, NULL);
        if (ret_select < 0) {
            perror("select");
            return -1;
        }

        if (FD_ISSET(STDIN_FILENO, &readfds)) {
            bzero(buf, sizeof(buf));
            int ret_read = read(STDIN_FILENO, buf, sizeof(buf));
            if (ret_read < 0) {
                perror("read");
                return -1;
            }
            int ret_send = send(net_fd, buf, sizeof(buf), 0);
            if (ret_send < 0) {
                perror("send");
                return -1;
            }
        }

        if (FD_ISSET(net_fd, &readfds)) {
            bzero(buf, sizeof buf);
            int ret_recv = recv(net_fd, buf, sizeof(buf), 0);
            if (ret_recv < 0) {
                perror("recv");
                return -1;
            } else if (ret_recv == 0) {  // 对端断开
                printf("client is closed\n");
                return 1;
            }

            printf("clint->buf:%s", buf);
        }
    }
}
