/****************************************************
 * @file    pthread_join_one.c
 * @brief   循环回收多个子线程
 * @author  bitofux
 * @date    2025-11-01
 ****************************************************/
#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

// 线程执行函数
void* start(void* arg) {
    int var = (int)arg;
    unsigned long th_id = pthread_self();
    printf("我的编号是:%d,我的线程id是:%lu\n", var + 1, pthread_self());

    // 线程退出
    pthread_exit((void*)th_id);
}

int main() {
    pthread_t tids[4];
    int ret = -1;

    for (int i = 0; i < 4; ++i) {
        ret = pthread_create(&tids[i], NULL, start, (void*)i);
        if (ret != 0) {
            fprintf(stderr, "pthread_create: %s", strerror(ret));
            exit(1);
        }
    }

    unsigned long* result[4];
    for (int i = 0; i < 4; ++i) {
        ret = pthread_join(tids[i], (void**)&result[i]);
        if (ret != 0) {
            fprintf(stderr, "pthread_create: %s", strerror(ret));
            exit(1);
        }
        printf("阻塞等待的子线程id: %lu\n", (unsigned long)result[i]);
    }
    pthread_exit(NULL);
}
