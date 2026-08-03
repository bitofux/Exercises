/****************************************************
 * @file    pthread_detach_attr.c
 * @brief   线程属性设置线程分离
 * @author  bitofux
 * @date    2025-11-04
 ****************************************************/
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

// 线程执行函数
void* start(void* arg) {
    int detachstate;
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    int ret = pthread_attr_getdetachstate(&attr, &detachstate);
    if (detachstate == PTHREAD_CREATE_DETACHED) {
        printf("child thread: 分离\n");
    } else {
        printf("child thread: 不分离\n");
    }
    pthread_exit((void*)100);
}
int main() {
    pthread_t tid;
    // 线程属性类型的变量
    pthread_attr_t attr;
    // 初始化线程属性
    pthread_attr_init(&attr);
    // 创建子线程,并将线程属性类型的变量的地址传入进去
    // 获取创建的线程是否分离
    int detachstate;
    int ret = pthread_attr_getdetachstate(&attr, &detachstate);
    // 判断状态
    if (detachstate == PTHREAD_CREATE_DETACHED) {
        printf("main thread: 分离\n");
    } else {
        printf("main thread: 不分离\n");
    }
    ret = pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
    if (ret != 0) {
        fprintf(stderr, "pthread_attr_setdetachstate failed\n");
        exit(1);
    }
    ret = pthread_create(&tid, &attr, start, NULL);
    if (ret != 0) {
        fprintf(stderr, "pthread_create failed\n");
        exit(1);
    }
    ret = pthread_join(tid, NULL);
    if (ret != 0) {
        fprintf(stderr, "pthread_join: %d\n", ret);
    }
    pthread_exit(NULL);
}
