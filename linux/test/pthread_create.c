/****************************************************
 * @file    pthread_create.c
 * @brief   简单的线程创建
 * @author  bitofux
 * @date    2025-10-31
 ****************************************************/

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// 线程所执行的函数
void* start(void* arg) {
    printf("In thread: thread id = %lu,pid = %u\n", pthread_self(), getpid());

    return NULL;
}
int main() {
    // 用于保存新创建线程的线程id
    pthread_t tid = 0;

    // 创建新的线程，使用start函数作为执行入口
    int ret = pthread_create(&tid, NULL, start, NULL);
    if (ret != 0) {
        fprintf(stderr, "pthread_create: %s", strerror(ret));
        exit(1);
    }
    printf("In main : thread id = %lu,pid = %u\n", pthread_self(), getpid());
    // 仅仅退出主线程
    pthread_exit(NULL);
}
