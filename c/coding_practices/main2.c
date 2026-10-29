/*
 * PROJECT : EXERCISES
 * FILE    : main2.c
 * AUTHOR  : bitofux
 * DATE    : 2026-10-27
 * BRIEF   :
 */

#include <stdio.h>

// 引用外部变量
extern int shared;

// 引用外部函数
extern int sum(int* a, int n);

// 全局变量
int array[2] = {1, 2};

// 静态全局变量
static int m = 10;

// 全局变量
int* arr_p = array;

// 全局变量
int c;

// 静态函数
static void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main(void) {
    // 局部静态变量
    static int b = 4;
    static int m;

    int val = sum(array, 2);
    swap(&val, &shared);

    printf("%d, %d\n", val, shared);
    return val;
}
