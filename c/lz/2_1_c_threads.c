/*
 * PROJECT : EXERCISES
 * FILE    : 2_1_c_threads.c
 * AUTHOR  : bitofux
 * DATE    : 2026-03-06
 * BRIEF   : C11的线程库
 */

#include <stdio.h>
#include <threads.h>
#include <time.h>

int thread_fun(void* args) {
    int times = 5;
    while (times--) {
        printf("%s\n", (char*)args);
        thrd_sleep(&(struct timespec){.tv_sec = 1,.tv_nsec = 0}, NULL);
    }
    thrd_exit(times);
}

int main() {
    // 1. 线程的标识
    thrd_t t1, t2;

    // 2. 创建两个线程
    thrd_create(&t1, thread_fun, "thread one");
    thrd_create(&t2, thread_fun, "thread two");

    int times[2] = {0};
    // 3.阻塞等待两个子线程执行完毕
    thrd_join(t1, &times[0]);
    thrd_join(t2, &times[1]);

    return 0;
}
