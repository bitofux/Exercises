/*
 * PROJECT : EXERCISES
 * FILE    : 3.tree_recursion.c
 * AUTHOR  : bitofux
 * DATE    : 2026-08-04
 * BRIEF   : 树(非线形)递归示例
 */
#include <stdio.h>

void func(int n) {
    if (n > 0) {
        printf(" ");
        func(n - 1);
        func(n - 1);
    }
}

int main() {
    int x = 3;

    func(3);
    printf("\n");
    return 0;
}
