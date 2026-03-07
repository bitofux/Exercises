/*
 * PROJECT : EXERCISES
 * FILE    : 2_2_data_race.c
 * AUTHOR  : bitofux
 * DATE    : 2026-03-06
 * BRIEF   : 数据竞争与原子变量
 */
#include <stdio.h>
#include <time.h>
#include <threads.h>

/*本例中，shard_data的数值随着每次程序的执行，结果都是不一样的，这就是数据竞争锁影响的结果
 * 若想解决data
 * race，可将shard_data变量的类型声明为原子类型，使得针对此变量的操作都是原子操作(在当前对此变量的操作未完成之前，不允许其他操作介入)*/
_Atomic long long int shard_data = 0;

int thread_proc1(void* args) {
    int* arg = (int*)args;
    for (int i = 0; i < *arg; ++i) {
        ++shard_data;
        // thrd_sleep(&(struct timespec){.tv_sec = 0, .tv_nsec = 500000000}, NULL);
    }
    return 0;
}
int thread_proc2(void* args) {
    int* arg = (int*)args;
    for (int i = 0; i < *arg; ++i) {
        --shard_data;
        // thrd_sleep(&(struct timespec){.tv_sec = 1, .tv_nsec = 0}, NULL);
    }
    return 0;
}

int main() {
    long long arg = 200000;
    thrd_t t[2] = {0};
    thrd_create(&t[0], thread_proc1, &arg);
    thrd_create(&t[1], thread_proc2, &arg);

    thrd_join(t[0], NULL);
    thrd_join(t[1], NULL);

    printf("shard_data: %lld\n", shard_data);
    return 0;
}
