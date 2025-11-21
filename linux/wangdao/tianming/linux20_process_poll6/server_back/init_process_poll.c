/****************************************************
 * @file    init_process_poll.c
 * @brief   初始化进程池
 * @author  bitofux
 * @date    2025-10-28
 ****************************************************/
#include "header.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>

int init_process_poll(child_proc_t* list, int num, int* sp) {
    pid_t pid = -1;
    for (int i = 0; i < num; ++i) {
        pid = fork();
        switch (pid) {
            case 0: {  // 子进程
                // 1.初始化每个子进程的状态
                close(sp[1]);
                while (1) {
                    // 2.接收父进程传来的文件对象
                    int fd = recv_fd_from_parent(sp[0]);
                    if (fd < 0) {
                        fprintf(stderr, "recv_fd_from_parent faild\n");
                        return -1;
                    }
                    // 3.做任务
                    int ret = do_work(fd);
                    if (ret < 0) {
                        fprintf(stderr, "do_work faild\n");
                        return -1;
                    }
                    printf("pid:%d,ppid:%d\n", getpid(), getppid());
                    // 4. 通知父进程完成任务
                    send(sp[0], "done", 4, 0);
                }
            }
            case -1: {
                fprintf(stderr, "fork failed\n");
                return -1;
            }
            default: {
                list[i].pid = pid;
                list[i].fd = sp[1];
                list[i].status = IDLESSE;
            }
        }
    }
    close(sp[0]);
    return 0;
}
