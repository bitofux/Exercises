/*
 * PROJECT : EXERCISES
 * FILE    : 2.recursion.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-08-03
 * BRIEF   : 递归函数示例(静态变量)
 */
#include <iostream>

// 无静态变量/全局变量
int func(int n) {
    if (n > 0) {
        return func(n - 1) + n;
    }

    return n;
}

int func_static(int n) {
    static int x = 0;

    if (n > 0) {
        x++;
        return func_static(n - 1) + x;
    }

    return 0;
}

int main() {
    int a = 5;

    std::cout << "a: " << func(a) << std::endl;
    std::cout << "a: " << func_static(a) << std::endl;
}
