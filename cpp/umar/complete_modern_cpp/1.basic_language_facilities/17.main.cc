/*
 * PROJECT : EXERCISES
 * FILE    : 17.main.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-09-08
 * BRIEF   : 测试匿名命名空间
 */
#include <iostream>

extern int add(int a, int b);

int main() {
    std::cout << add(10, 20);

    return 0;
}
