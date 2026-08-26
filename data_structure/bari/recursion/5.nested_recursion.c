/*
 * PROJECT : EXERCISES
 * FILE    : 5.nested_recursion.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-08-06
 * BRIEF   : 嵌套递归
 */
#include <stdio.h>

int func(int n) {
    if (n > 100) {
        return n - 10;
    } else {
        return func(func(n + 11));
    }
}

int main() {
    printf("%d\n", func(95));

    return 0;
}
