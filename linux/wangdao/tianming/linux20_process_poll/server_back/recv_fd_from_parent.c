/****************************************************
 * @file    recv_fd_from_parent.c
 * @brief   从父进程读取文件对象
 * @author  bitofux
 * @date    2025-10-28
 ****************************************************/
#include "header.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
int recv_fd_from_parent(int fd) {
    struct msghdr msg;
    memset(&msg, 0, sizeof(msg));
    char buf[10] = {0};
    struct iovec iov = {.iov_base = buf, .iov_len = sizeof(buf)};
    size_t rights = CMSG_SPACE(sizeof(int));
    char control[rights];
    memset(control, 0, sizeof(control));
    msg.msg_iov = &iov;
    msg.msg_iovlen = 1;
    msg.msg_control = control;
    msg.msg_controllen = rights;

    int ret = recvmsg(fd, &msg, 0);
    if (ret < 0) {
        perror("recvmsg");
        return -1;
    }
    struct cmsghdr* cmsg = CMSG_FIRSTHDR(&msg);
    int* net_fd = (int*)CMSG_DATA(cmsg);
    return *net_fd;
}
