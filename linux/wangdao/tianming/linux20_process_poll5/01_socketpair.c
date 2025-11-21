/****************************************************
 * @file    01_socketpair.c
 * @brief   测试socketpair
 * @author  bitofux
 * @date    2025-10-18
 ****************************************************/
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/wait.h>

int main() {
    int sv[2] = {0};
    // 创建两个本地socket对象,这两个socket对象的接收和
    // 发送队列是连接着的 全双工
    int _socketpair = socketpair(AF_LOCAL, SOCK_STREAM | SOCK_CLOEXEC, 0, sv);
    if (_socketpair < 0) {
        perror("socketpair");
        return -1;
    }
    pid_t pid = fork();
    if (pid == 0) {
        printf("i am child process!! pid: %d", getpid());
        close(sv[0]);
        // 向子进程发送hello
        send(sv[1], "hello", 5, 0);
        close(sv[1]);
        exit(1);
    } else {
        printf("i am parent process!! pid: %d\n", getpid());
        close(sv[1]);
        char buf[20] = {0};
        int ret = recv(sv[0], buf, sizeof(buf), 0);
        buf[ret] = '\0';
        write(STDOUT_FILENO, buf, ret);
        wait(NULL);
    }
}
