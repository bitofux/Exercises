/*
 * PROJECT : EXERCISES
 * FILE    : 7.factorial.c
 * AUTHOR  : bitofux
 * DATE    : 2026-08-15
 * BRIEF   : 求给定一个整数的阶乘
 */
#include <stdio.h>

// 递归计算
static int fact_recursion(int n) {
    if (n == 0) {
        return 1;
    }

    return fact_recursion(n - 1) * n;
}

// 循环计算
static int fact_circle(int n) {
    if (n == 0 || n == 1){
        return 1;
    }
    int sum = 1;
    while (n != 0) {
        sum *= n;
        n--;
    }

    return sum;
}

int main() {
    // 递归计算
    printf("%d\n", fact_recursion(3));

    // 循环计算
    printf("%d\n", fact_circle(3));
    return 0;
}
