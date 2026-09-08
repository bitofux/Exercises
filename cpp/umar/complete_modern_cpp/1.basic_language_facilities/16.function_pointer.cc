/*
 * PROJECT : EXERCISES
 * FILE    : 16.function_pointer.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-09-08
 * BRIEF   : 函数指针
 */
#include <iostream>

void print(int count, char ch) {
    using namespace std;
    for (int i = 0; i < count; ++i) {
        std::cout << ch;
    }
}

int main() {
    print(5, '#');

    // 定义一个函数指针
    void (*fun_ptr)(int, char) = print;

    std::cout << std::endl;

    // 使用函数指针调用print函数
    (*fun_ptr)(6, '@');
    std::cout << std::endl;
    fun_ptr(5, '#');
    std::cout << std::endl;

    return 0;
}
