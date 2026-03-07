/*
 * PROJECT : EXERCISES
 * FILE    : 2_3_mutex.c
 * AUTHOR  : bitofux
 * DATE    : 2026-03-07
 * BRIEF   : C11中的锁
 */
#include <stdio.h>
#include <threads.h>
#include <time.h>

long long int shard_data = 0;

// 锁也是一种资源
mtx_t mutex;
int thread_proc1(void* args) {
    int* arg = (int*)args;

    for (int i = 0; i < *arg; ++i) {
        mtx_lock(&mutex);
        ++shard_data;
        mtx_unlock(&mutex);
    }

    return 0;
}
int thread_proc2(void* args) {
    int* arg = (int*)args;

    for (int i = 0; i < *arg; ++i) {
        mtx_lock(&mutex);
        --shard_data;
        mtx_unlock(&mutex);
    }

    return 0;
}

int main() {
    long int time = 200000;
    thrd_t thread[2] = {0};
    // 初始化锁
    mtx_init(&mutex, mtx_plain);
    thrd_create(&thread[0], thread_proc1, &time);
    thrd_create(&thread[1], thread_proc2, &time);

    thrd_join(thread[0], NULL);
    thrd_join(thread[1], NULL);

    printf("shard_data: %lld\n", shard_data);

    return 0;
}
