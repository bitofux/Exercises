/****************************************************
 * @file    init_process_poll.c
 * @brief   初始化进程池源文件
 * @author  bitofux
 * @date    2025-11-01
 ****************************************************/
#include <sys/sendfile.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include "header.h"
#include <sys/stat.h>
#include <sys/mman.h>
#define CHUNK 64u * 1024
int init_process_poll(proc_t* list, int num) {
    // 1. 要为每个进程创建一对socketpair,否则多个进程共用一对
    // socketpair会出现race condition
    for (int i = 0; i < num; ++i) {
        int sp[2];
        int soc_pair = socketpair(AF_LOCAL, SOCK_STREAM, 0, sp);
        if (soc_pair < 0) {
            perror("socketpair");
            return -1;
        }
        pid_t pid = fork();
        if (pid == 0) {
            // 子进程逻辑
            // 1. 关闭对一个文件对象的引用
            close(sp[1]);
            while (1) {
                // 2. 接收父进程传来的数据
                // 2.1 定义一个变量保存从父进程传来的数据
                int net_fd = -1;
                if (recv_fd_from_parent(sp[0], &net_fd) < 0) {
                    fprintf(stderr, "recv_fd_from_parent failed\n");
                    return -1;
                }
                // 3. 数据处理
                if (work(net_fd) < 0) {
                    fprintf(stderr, "work failed\n");
                    return -1;
                }
                // 4. 数据处理完成之后，通知父进程
                int ret = send(sp[0], "done", strlen("done"), 0);
                if (ret < 0) {
                    perror("send");
                    return -1;
                }
                // 暂时是数据处理结束之后,关闭客户端
                close(net_fd);
            }
        } else if (pid == -1) {
            fprintf(stderr, "fork failed\n");
            return -1;
        } else {
            // 父进程逻辑
            // 1. 关闭对一个文件对象的引用
            close(sp[0]);
            // 2. 父进程保存子进程的信息
            list[i].local_fd = sp[1];
            list[i].pid = pid;
            list[i].status = NOT_BUSY;
        }
    }
    return 0;
}
int recv_fd_from_parent(int fd, int* net_fd) {
    struct msghdr msg;
    memset(&msg, 0, sizeof(msg));

    char ch = '0';
    struct iovec iov = {.iov_base = &ch, .iov_len = sizeof(ch)};
    msg.msg_iov = &iov;
    msg.msg_iovlen = 1;

    size_t rights = CMSG_SPACE(sizeof(int));
    char control[rights];
    memset(control, 0, sizeof(control));
    msg.msg_control = control;
    msg.msg_controllen = rights;
    size_t ret = recvmsg(fd, &msg, 0);
    printf("after recvmsg\n");
    if (ret < 0) {
        perror("recvmsg");
        return -1;
    }
    struct cmsghdr* cmsg = CMSG_FIRSTHDR(&msg);
    int* data = (int*)CMSG_DATA(cmsg);
    *net_fd = *data;
    printf("*data: %d\n", *data);
    return 0;
}

int work(int fd) {
    const char* file_name = "1.txt";
    size_t file_length = strlen(file_name);
    // 发送文件名大小+发送文件名称
    int ret_send = send(fd, &file_length, sizeof(size_t), MSG_NOSIGNAL);
    if (ret_send < 0) {
        perror("send");
    }
    ret_send = send(fd, file_name, file_length, MSG_NOSIGNAL);
    if (ret_send < 0) {
        perror("send");
    }

    // 打开文件，读取文件内容
    int file_fd = open(file_name, O_RDONLY);
    if (file_fd < 0) {
        perror("open");
        return -1;
    }
    // 发送文件大小
    struct stat st;
    memset(&st, 0, sizeof(st));
    int ret_fstat = fstat(file_fd, &st);
    if (ret_fstat < 0) {
        perror("fstat");
    }
    off_t file_size = st.st_size;
    ret_send = send(fd, &file_size, sizeof(off_t), MSG_NOSIGNAL);
    if (ret_send < 0) {
        perror("send");
    }
    // 偏移量,使用sendfile时会自动更新偏移量
    off_t offset = 0;
    size_t to_send;
    while (offset < file_size) {
        to_send = CHUNK;
        // 如果要发送的数据小于chunk,那么需要文件大小
        // 减去偏移量获取需要发送的数据，否则会造成
        // 文件越界发送
        if (file_size - offset < CHUNK) to_send = file_size - offset;
        ssize_t ret_sendfile = sendfile(fd, file_fd, &offset, to_send);
        if (ret_sendfile <= 0) {
            if (errno == EINTR) continue;
            perror("sendfile");
            break;
        }
    }

    return 0;
}
