/****************************************************
 * @file    send_fd_to_chi_proc.c
 * @brief   发送父进程的fd到子进程
 * @author  bitofux
 * @date    2025-11-01
 ****************************************************/
#include <asm-generic/socket.h>
#include <stdio.h>
#include <sys/socket.h>
#include "header.h"

// 1. list保存子进程的信息
// 2. fd是需要发送文件对象对应的文件描述符
int send_fd_to_chi_proc(proc_t* list, int num, int fd) {
    struct msghdr msg;
    memset(&msg, 0, sizeof(msg));
    // 1. 设置普通数据
    char ch;
    if (fd == 0)
        ch = 'e';
    else
        ch = 's';
    struct iovec iov = {.iov_base = &ch, .iov_len = sizeof(ch)};
    // 2. 设置控制信息
    size_t rights = CMSG_SPACE(sizeof(int));
    char control[rights];
    memset(control, 0, sizeof(control));
    msg.msg_name = NULL;
    msg.msg_namelen = 0;
    msg.msg_iov = &iov;
    msg.msg_iovlen = 1;
    msg.msg_control = control;
    msg.msg_controllen = rights;
    // 2.1获取第一个控制信息的起始地址
    struct cmsghdr* cmsg = CMSG_FIRSTHDR(&msg);
    cmsg->cmsg_level = SOL_SOCKET;
    cmsg->cmsg_type = SCM_RIGHTS;
    cmsg->cmsg_len = CMSG_LEN(sizeof(int));
    // 2.2获取第一个控制信息中数据区域的起始地址
    int* data = (int*)CMSG_DATA(cmsg);
    *data = fd;
    if (ch == 'e') {
        for (int i = 0; i < PROC_NUM; ++i) {
            size_t ret = sendmsg(list[i].local_fd, &msg, 0);
        }
    } else {
        // 3. 判断哪个子进程的状态是空闲的
        // 空闲状态就将数据发送过去,并将对应子进程的状态设为BUSY
        for (int i = 0; i < PROC_NUM; ++i) {
            if (list[i].status == NOT_BUSY) {
                size_t ret = sendmsg(list[i].local_fd, &msg, 0);
                if (ret < 0) {
                    perror("sendmsg");
                    return -1;
                }
                list[i].status = BUSY;
                break;
            }
        }
    }
    return 0;
}
