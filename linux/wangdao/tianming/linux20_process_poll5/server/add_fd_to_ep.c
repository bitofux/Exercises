/****************************************************
 * @file    add_fd_to_ep.c
 * @brief   添加需要监听的文件对象到epoll实例
 * @author  bitofux
 * @date    2025-11-01
 ****************************************************/
#include <stdio.h>
#include <sys/epoll.h>
#include "header.h"

int add_fd_to_ep(int ep_fd, int fd, uint32_t events) {
    struct epoll_event event = {.data.fd = fd, .events = EPOLLIN};
    if (epoll_ctl(ep_fd, EPOLL_CTL_ADD, fd, &event) < 0) {
        perror("epoll_ctl");
        return -1;
    }
    return 0;
}
