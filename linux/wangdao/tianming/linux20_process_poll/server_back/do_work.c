/****************************************************
 * @file    do_work.c
 * @brief   子进程完成任务
 * @author  bitofux
 * @date    2025-10-28
 ****************************************************/
#include "header.h"
#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>

int do_work(int fd) {
    char buf[1024] = {0};
    int ret_read = recv(fd, buf, 1024, 0);
    if (ret_read == 0) {
        close(fd);
        return -1;
    }
    printf("%d:%d->buf: %s\n", getpid(), getppid(), buf);
    send(fd, "byebye", 6, 0);
    return 0;
}
