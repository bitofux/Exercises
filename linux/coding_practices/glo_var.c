/****************************************************
 * @file    glo_var.c
 * @brief   线程间共享数据
 * @author  bitofux
 * @date    2025-10-31
 ****************************************************/
#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

// 定义一个全局变量
int var = 200;

// 线程执行函数
void* start(void* arg) {
    var = 300;
    printf("thread id: %lu,var: %d\n", pthread_self(), var);

    return NULL;
}

int main() {
    pthread_t tid;

    int ret = -1;

    printf("thread id: %lu,var: %d\n", pthread_self(), var);
    ret = pthread_create(&tid, NULL, start, NULL);
    if (ret != 0) {
        fprintf(stderr, "pthread_create: %s", strerror(ret));
        exit(1);
    }

    // 主线程睡眠2秒
    sleep(2);

    printf("thread id: %lu,var: %d\n", pthread_self(), var);

    return 0;
}
