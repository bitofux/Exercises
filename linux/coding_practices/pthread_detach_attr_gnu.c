/****************************************************
 * @file    pthread_detach_attr_gnu.c
 * @brief   非C标准
 * @author  bitofux
 * @date    2025-11-04
 ****************************************************/
#define _GNU_SOURCE
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void* start(void* arg) {
    pthread_attr_t a;
    int state;

    // 非标准扩展：把“当前线程”的真实属性抓出来
    if (pthread_getattr_np(pthread_self(), &a) != 0) {
        perror("pthread_getattr_np");
        pthread_exit(NULL);
    }
    pthread_attr_getdetachstate(&a, &state);
    printf("child thread: %s\n", state == PTHREAD_CREATE_DETACHED ? "分离" : "不分离");
    pthread_attr_destroy(&a);

    // 分离线程不要返回给 join 者；直接结束即可
    pthread_exit((void*)100);
}

int main() {
    pthread_t tid;
    pthread_attr_t attr;
    int state;

    pthread_attr_init(&attr);

    // 看看“属性对象”的默认值（不是线程状态）
    pthread_attr_getdetachstate(&attr, &state);
    printf("main: 属性对象默认 = %s\n",
           state == PTHREAD_CREATE_DETACHED ? "分离" : "不分离");  // 一定是不分离

    // 设置创建出来的线程为“分离”
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);

    if (pthread_create(&tid, &attr, start, NULL) != 0) {
        perror("pthread_create");
        exit(1);
    }
    pthread_attr_destroy(&attr);

    // 这时 tid 是分离态，join 会失败（EINVAL）
    int ret = pthread_join(tid, NULL);
    if (ret != 0) {
        printf("pthread_join 失败，ret=%d（分离线程不可 join 是预期行为）\n", ret);
    }

    // 用于让子线程有机会打印
    sleep(1);
    return 0;
}
