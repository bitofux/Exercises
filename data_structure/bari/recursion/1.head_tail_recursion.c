/*
 * PROJECT : EXERCISES
 * FILE    : 1.head_tail_recursion.c
 * AUTHOR  : bitofux
 * DATE    : 2026-08-01
 * BRIEF   : 递归示例
 */
#include <stdio.h>

// 尾递归：先执行递归调用前的代码，再进行递归调用
// 输出：3 2 1
void func_one(int n) {
    if (n > 0) {
        // 先执行递归前的代码
        printf("%d ", n);

        // 执行递归调用
        func_one(n - 1);
    }
}

// 头递归：先执行递归调用，再执行代码
// 输出：1 2 3
void func_two(int n) {
    if (n > 0) {
        // 先执行递归调用
        func_two(n - 1);
        // 再执行输出代码
        printf("%d ", n);
    }
}
int main() {
    int x = 3;
    // func_one(3);
    func_two(x);
    return 0;
}
