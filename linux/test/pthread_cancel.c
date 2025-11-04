/****************************************************
 * @file    pthread_cancel.c
 * @brief   取消和杀死一个线程
 * @author  bitofux
 * @date    2025-11-03
 ****************************************************/
#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>

// 线程执行函数
void* start(void* arg) {
    // int count = 3;
    // while (count--) {
    //     printf("count: %d\n", count);
    //     sleep(1);
    // }
    while (1) {
        pthread_testcancel();
    }
    pthread_exit((void*)666);
}

int main() {
    pthread_t tid;

    int ret = pthread_create(&tid, NULL, start, NULL);
    if (ret != 0) {
        fprintf(stderr, "pthread_create failed: %s\n", strerror(ret));
    }

    void* result;
    // 取消这个线程,使用pthread_join函数等待并获取退出状态
    pthread_cancel(tid);
    int ret_join = pthread_join(tid, (void**)&result);
    if (ret_join != 0) {
        fprintf(stderr, "pthread_join failed: %s\n", strerror(ret_join));
    }
    printf("被取消线程的退出状态是: %d\n", (int)result);
    pthread_exit(NULL);
}
