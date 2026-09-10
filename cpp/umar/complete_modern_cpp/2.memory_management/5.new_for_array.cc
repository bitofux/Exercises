/*
 * PROJECT : EXERCISES
 * FILE    : 5.new_for_array.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-09-10
 * BRIEF   : 使用new的另外一种为数组申请堆内存
 */
#include <cstring>
#include <iostream>

int main() {
    int* ptr = new int[5]{1, 2, 3, 4, 5};

    delete[] ptr;
    ptr = nullptr;

    char* str = new char[4];
    strcpy(str, "C++");
    std::cout << "str: " << str << "\n";
    std::cout << sizeof("C++") << std::endl;

    char *str1 = new char[4]{"C++"};
    char *str2 = new char[4]{'C','+','+','\0'};

    std::cout << "str1: " << str1 << std::endl;
    std::cout << "str2: " << str2 << std::endl;

    return 0;
}
