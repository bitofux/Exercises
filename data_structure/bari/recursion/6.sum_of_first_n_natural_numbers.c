/*
 * PROJECT : EXERCISES
 * FILE    : 6.sum_of_first_n_natural_numbers.c
 * AUTHOR  : bitofux
 * DATE    : 2026-08-12
 * BRIEF   : 利用递归计算前n个自然数的和
 * -- 当 n = 0 时，sum(n) = 0
 * -- 当 n > 0 时，sum(n) = sum(n - 1) + n
 */

#include <stdio.h>

// 1. 递归计算
static int recursion_sum(int n) {
    if (n == 0) {
        return 0;
    }

    return recursion_sum(n - 1) + n;
}

// 2. 直接公式计算
static int formula_sum(int n) { return n * (n + 1) / 2; }

// 3. 循环计算
static int circle_sum(int n) {
    int sum = 0;
    while (n) {
        sum += n;
        --n;
    }

    return sum;
}
int main(void) {
    // 1. 递归计算
    printf("%d\n", recursion_sum(5));

    // 2. 直接公式计算
    printf("%d\n",formula_sum(5));

    // 3. 循环计算
    printf("%d\n",circle_sum(5));

    return 0;
}
