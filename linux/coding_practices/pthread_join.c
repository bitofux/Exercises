/***************************************************
 * @file    pthread_join.c
 * @brief   回收特定的子线程
 * @author  bitofux
 * @date    2025-11-01
 ****************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

typedef struct {
    char name[20];
    int a;
} exit_t;

// 线程执行函数
void* start(void* arg) {
    // 创建一个退出类型的变量
    exit_t* var = (exit_t*)malloc(sizeof(exit_t));
    strcpy(var->name, "bitofux");

    pthread_exit((void*)var);
}
// 线程执行函数
void* routine(void* arg) {
    int* var = malloc(sizeof(int));
    *var = 200;
    printf("地址值: %p\n", var);

    pthread_exit((void*)var);
}
int main() {
    // 保存所创建的子线程的id
    pthread_t tid;

    // 创建子线程并传递参数
    int ret = pthread_create(&tid, NULL, start, NULL);
    if (ret != 0) {
        fprintf(stderr, "pthread_create: %s", strerror(ret));
        exit(1);
    }

    exit_t* revtal;
    // 阻塞等待子线程并回收退出状态
    int ret_join = pthread_join(tid, (void**)&revtal);

    printf("子线程的退出状态,a: %d,name: %s\n", revtal->a, revtal->name);
}
