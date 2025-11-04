/****************************************************
 * @file    pthread_detach.c
 * @brief   线程分离
 * @author  bitofux
 * @date    2025-11-03
 ****************************************************/
#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
// 线程执行函数
void* start(void* arg) {
    int count = 3;
    while (count--) {
        printf("count: %d\n", count);
    }
    sleep(1);
    pthread_exit((void*)1);
}

int main() {
    pthread_t tid;

    int ret = pthread_create(&tid, NULL, start, NULL);
    if (ret != 0) {
        fprintf(stderr, "pthread_create: %s", strerror(ret));
        exit(1);
    }
    // 线程分离
    int ret_detach = pthread_detach(tid);
    if (ret_detach != 0) {
        fprintf(stderr, "pthread_detach failed: %s", strerror(ret_detach));
        exit(1);
    }
    int* result;
    // 线程分离,使用join等待
    int ret_join = pthread_join(tid, (void**)&result);
    if (ret_join != 0) {
        fprintf(stderr, "pthread_join failed: %s\n", strerror(ret_join));
    } else {
        fprintf(stderr, "pthread_join success\n");
    }
    pthread_exit(NULL);
}
