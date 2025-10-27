#define _POSIX_C_SOURCE 199312L
#include "strings.h"
#include "sys_header.h"

typedef enum { ALIVE, DEAD } sta_t;
typedef struct {
    int fd;
    sta_t status;
    struct timespec start;
} conn_t;

conn_t conn_array[20];
int size = 0;
int main(int argc, char** argv) {
    if (argc < 3 || argc > 3) {
        fprintf(stderr, "usage: exec ip port\n");
        return -1;
    }

    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
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

    int ret_listen = listen(sock_fd, 64);
    if (ret_listen < 0) {
        perror("ret_listen");
        return 0;
    }

    int ep_fd = epoll_create1(EPOLL_CLOEXEC);
    if (ep_fd < 0) {
        perror("epoll_create1");
        return -1;
    }
    struct epoll_event event = {.events = EPOLLIN, .data.fd = sock_fd};
    epoll_ctl(ep_fd, EPOLL_CTL_ADD, sock_fd, &event);

    char buf[1024] = {0};
    struct epoll_event events[5];

    while (1) {
        bzero(&events, sizeof(events));
        int epoll_num = epoll_wait(ep_fd, events, 5, 1000);
        if (epoll_num < 0) {
            perror("epoll_wait");
            return -1;
        }
        for (int i = 0; i < epoll_num; ++i) {
            int fd = events[i].data.fd;
            uint32_t eve = events[i].events;
            if (fd == sock_fd) {
                // 取出完成三次握手的连接
                // 创建一个用于通信的socket的文件对象
                int net_fd = accept(fd, NULL, NULL);
                if (net_fd < 0) {
                    perror("accept");
                    return -1;
                }
                // 添加到监听集合
                event.data.fd = net_fd;
                event.events = EPOLLIN;
                epoll_ctl(ep_fd, EPOLL_CTL_ADD, net_fd, &event);

                // 添加到conn_array数组
                ++size;
                conn_array[size - 1].fd = net_fd;
                conn_array[size - 1].status = ALIVE;
                clock_gettime(CLOCK_MONOTONIC, &conn_array[size - 1].start);
                continue;
            } else {
                if (eve & EPOLLIN) {
                    for (int i = 0; i < size; ++i) {
                        //先在数据结构中找到这个连接对象 -> 读数据 -> 移除或者转发数据
                        //先读数据 -> 若为0 -> 在数据结构中找到这个连接对象并移除监听设置状态 -> 不为0就转发数据
                        if (conn_array[i].fd == fd && conn_array[i].status == ALIVE) {
                            bzero(buf, sizeof(buf));
                            int ret_recv = recv(fd, buf, sizeof(buf), 0);
                            if (ret_recv == 0) {
                                // 移除监听列表
                                event.events = EPOLLIN;
                                event.data.fd = fd;
                                epoll_ctl(ep_fd, EPOLL_CTL_DEL, fd, &event);
                                // 改变状态
                                conn_array[i].status = DEAD;
                                // 关闭文件对象
                                close(fd);
                                break;
                            }
                            clock_gettime(CLOCK_MONOTONIC, &conn_array[i].start);
                            if (ret_recv < 0) {
                                perror("recv");
                                return -1;
                            }
                            for (int j = 0; j < size; j++) {
                                if (conn_array[j].fd != fd && conn_array[j].status == ALIVE) {
                                    int ret_send = send(conn_array[j].fd, buf, ret_recv, 0);
                                    if (ret_send < 0) {
                                        perror("send");
                                        return -1;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        struct timespec end;
        clock_gettime(CLOCK_MONOTONIC, &end);
        for (int i = 0; i < size; ++i) {
            if (conn_array[i].status == ALIVE) {
                double el = (end.tv_sec - conn_array[i].start.tv_sec) +
                            ((end.tv_nsec - conn_array[i].start.tv_nsec) / 1e9);
                printf("%d: %.6f\n", conn_array[i].fd, el);
                if (el > 20.0) {
                    // 移除监听列表
                    event.events = EPOLLIN;
                    event.data.fd = conn_array[i].fd;
                    epoll_ctl(ep_fd, EPOLL_CTL_DEL, conn_array[i].fd, &event);
                    // 改变状态
                    conn_array[i].status = DEAD;
                    // 关闭文件对象
                    close(conn_array[i].fd);
                }
            }
        }
    }
}
