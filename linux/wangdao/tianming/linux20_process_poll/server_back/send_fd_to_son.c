/****************************************************
 * @file    send_fd_to_son.c
 * @brief   发送文件对象到子进程
 * @author  bitofux
 * @date    2025-10-28
 ****************************************************/
#include "header.h"
#include <asm-generic/socket.h>
#include <bits/types/struct_iovec.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
void send_fd_to_son(child_proc_t* list, int nums, int fd, int* sp) {
    struct msghdr msg;
    memset(&msg, 0, sizeof(msg));
    struct iovec iov = {.iov_base = "bitofux", .iov_len = strlen("bitofux")};

    size_t rights = CMSG_SPACE(sizeof(int));
    char control[rights];
    memset(control, 0, sizeof(control));

    msg.msg_name = NULL;
    msg.msg_namelen = 0;
    msg.msg_iov = &iov;
    msg.msg_iovlen = 1;
    msg.msg_control = control;
    msg.msg_controllen = rights;

    struct cmsghdr* cmsg = CMSG_FIRSTHDR(&msg);
    cmsg->cmsg_len = CMSG_LEN(sizeof(int));
    cmsg->cmsg_level = SOL_SOCKET;
    cmsg->cmsg_type = SCM_RIGHTS;

    *((int*)CMSG_DATA(cmsg)) = fd;

    for (int i = 0; i < nums; ++i) {
        if (list[i].status == IDLESSE) {
            sendmsg(sp[1], &msg, 0);
            break;
        }
    }
}
