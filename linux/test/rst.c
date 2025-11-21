/****************************************************
 * @file    rst.c
 * @brief   测试服务器
 * @author  bitofux
 * @date    2025-11-05
 ****************************************************/
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
// SIGPIPE信号处理函数
void sigpipe(int sig_num) {
    char msg[30] = {0};
    snprintf(msg, sizeof(msg), "Caught SIGPIPE Signal: %d\n", sig_num);
    write(STDOUT_FILENO, msg, sizeof(msg));
    sleep(1);
}
int main(int argc, char** argv) {
    // 注册SIGPIPE信号
    struct sigaction sa = {};
    memset(&sa, 0, sizeof(sa));
    // 被信号中断的系统调用自动重启
    sa.sa_flags = SA_RESTART;
    sa.sa_handler = sigpipe;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGPIPE, &sa, NULL);
    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd < 0) {
        perror("socket");
        return -1;
    }
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    (void)inet_pton(AF_INET, argv[1], &server_addr.sin_addr);

    int reuse = 1;
    int ret = setsockopt(sock_fd, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse));
    if (ret < 0) {
        perror("setsockopt");
        return -1;
    }
    ret = bind(sock_fd, (const struct sockaddr*)&server_addr, sizeof(server_addr));
    if (ret < 0) {
        perror("bind");
    }

    ret = listen(sock_fd, 2);
    if (ret < 0) {
        perror("listen");
        return -1;
    }

    int net_fd = -1;
    do {
        net_fd = accept(sock_fd, NULL, NULL);
    } while (net_fd < 0 && errno == EINTR);

    while (1) {
        sleep(1);
        printf("starting to send...\n");
        // ret = send(net_fd, "hi", 2, 0);
        ret = send(net_fd, "hi", 2, MSG_NOSIGNAL);
        if (ret < 0) {
            perror("send");
        }
        printf("ending...\n");
    }
}
