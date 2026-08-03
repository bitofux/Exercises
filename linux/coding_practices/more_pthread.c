/****************************************************
 * @file    more_pthread.c
 * @brief   循环创建多个线程
 * @author  bitofux
 * @date    2025-10-31
 ****************************************************/
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define NUM 5

// 子线程中嵌套调用的函数
int func(int a) {
    // return a;
    // exit(1);
    pthread_exit(NULL);
}
// 线程执行函数
void* start(void* arg) {
    int i = (int)arg;

    sleep(i);
    if (i == 3) {
        func(10);
    }
    fprintf(stdout, "%dth thread tid %lu,pid %u\n", i, pthread_self(), getpid());

    return NULL;
}
int main() {
    // 创建一个数组，保存多个线程的每个id
    pthread_t tids[NUM] = {0};

    // 保存pthread_create的返回值
    int ret = -1;
    // 循环创建多个线程
    int i;
    for (i = 0; i < NUM; ++i) {
        ret = pthread_create(&tids[i], NULL, start, (void*)i);
        if (ret != 0) {
            fprintf(stderr, "pthread_create: %s", strerror(ret));
            exit(1);
        }
    }

    fprintf(stdout, "main thread tid %lu,pid %u\n", pthread_self(), getpid());
    pthread_exit(NULL);
}
