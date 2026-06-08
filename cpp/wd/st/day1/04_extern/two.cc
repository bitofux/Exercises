/*
 * PROJECT : DAY1
 * FILE    : two.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-05-30
 * BRIEF   : 使用extern引用one.cc的实体
 */

#include <iostream>

// 声明一个变量，不分配地址
extern int a;

// 声明一个函数
extern void func();

int main() {
    std::cout << "a: " << a << "\n";

    func();
}
