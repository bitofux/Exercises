// 实现地址复用: 使用setsockopt函数
#define _POSIX_C_SOURCE 200112L
#include <bits/types/struct_timeval.h>
#include <string.h>
#include <bits/time.h>
#include <stdint.h>
#include <stdio.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <time.h>
#include <unistd.h>
#include "sys_header.h"

typedef enum status { ALIVE, DEAD } status_t;
// 将每个连接抽象成一个连接实体 方便为这个连接实体
// 增加属性
typedef struct {
    int _fd;
    status_t sta;
    struct timespec start;
} conn_t;

// 创建一个数组，用于保存每个连接实体
conn_t conn_array[64];
// 保存数组中有效连接的个数
uint16_t size = 0;
// 用户态缓冲区
char buffer[1024] = {0};
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

    // 实现地址复用：不会改变TIME_WAIT状态
    int reuse = 1;
    int ret_setsockopt = setsockopt(sock_fd, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse));
    if (ret_setsockopt == -1) {
        perror("setsockopt");
        close(sock_fd);
        return -1;
    }
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

    // 由于每次调用select就会更改用户态传入的监听集合
    // 因此我们创建两个这样的集合，一个是用于在用户态
    // 保存传入select之前的监听集合,并方便后续移除
    fd_set readfds;       // 传入select的集合
    fd_set base_readfds;  // 用户态用户添加和删除fd的集合

    // 首先将用户监听全连接队列的socket对象添加到
    // base_readfds
    FD_ZERO(&base_readfds);
    FD_SET(sock_fd, &base_readfds);

    struct timeval tvl;
    while (1) {
        // 将要传入的selec的集合清空
        FD_ZERO(&readfds);
        // 将base_readfds的数据复制到readfds
        memcpy(&readfds, &base_readfds, sizeof(base_readfds));
        // 不仅要重置监听集合 还需要重新设置超时时间
        tvl.tv_sec = 20;
        tvl.tv_usec = 0;
        // 调用select
        int ret_select = select(64, &readfds, NULL, NULL, &tvl);
        if (ret_select == 0) {
            // 超时将全部对象剔除
            for (uint16_t i = 0; i < size; ++i) {
                conn_array[i].sta = DEAD;
                FD_CLR(conn_array[i]._fd, &base_readfds);
                close(conn_array[i]._fd);
                continue;
            }
        }
        if (ret_select < 0) {
            perror("select");
            return -1;
        }

        // 全连接队列来了新的三次握手连接
        if (FD_ISSET(sock_fd, &readfds)) {
            // 新连接到来
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
            ++size;

            // 添加到连接实体数组中
            conn_array[size - 1]._fd = net_fd;
            conn_array[size - 1].sta = ALIVE;
            clock_gettime(CLOCK_MONOTONIC, &conn_array[size - 1].start);

            // 添加到监听集合中
            FD_SET(net_fd, &base_readfds);
        }

        // 连接对象就绪
        for (uint16_t i = 0; i < size; ++i) {
            memset(buffer, 0, sizeof(buffer));
            if ((conn_array[i].sta == ALIVE) && FD_ISSET(conn_array[i]._fd, &readfds)) {
                // 更新时间
                clock_gettime(CLOCK_MONOTONIC, &conn_array[i].start);
                // 读取数据
                int ret_recv = recv(conn_array[i]._fd, buffer, sizeof(buffer), 0);
                if (ret_recv < 0) {
                    perror("recv");
                    return -1;
                }
                // 判断是不是对端断开
                if (ret_recv == 0) {
                    // 将其的状态改为DEAD
                    conn_array[i].sta = DEAD;
                    // 将其在监听集合中移除
                    FD_CLR(conn_array[i]._fd, &base_readfds);
                    // close
                    close(conn_array[i]._fd);

                    continue;
                }
                // 将数据发送到其他客户端
                for (uint16_t j = 0; j < size; j++) {
                    if ((conn_array[j].sta == ALIVE) && conn_array[i]._fd != conn_array[j]._fd) {
                        int ret_send = send(conn_array[j]._fd, buffer, sizeof(buffer), 0);
                        if (ret_send < 0) {
                            perror("send");
                            return -1;
                        }
                    }
                }
            }
        }
        // 超时退出: 获取当前时间
        struct timespec end;
        clock_gettime(CLOCK_MONOTONIC, &end);
        double el;
        for (uint16_t i = 0; i < size; ++i) {
            if (conn_array[i].sta == ALIVE) {
                el = (double)(end.tv_sec - conn_array[i].start.tv_sec) +
                     (double)(end.tv_nsec - conn_array[i].start.tv_nsec) / 1e9;
                printf("%d->el:%.6f\n", conn_array[i]._fd, el);
                if (el > 10.0) {
                    conn_array[i].sta = DEAD;
                    FD_CLR(conn_array[i]._fd, &base_readfds);
                    close(conn_array[i]._fd);
                }
            }
        }
    }
}
