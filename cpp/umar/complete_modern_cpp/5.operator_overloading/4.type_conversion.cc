/*
 * PROJECT : EXERCISES
 * FILE    : 4.type_conversion.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-10-14
 * BRIEF   : 类型转换
 */

#include <iostream>

#include "integer.hpp"

// 基本类型 -> 基本类型
void test() {
    int a = 10;
    // char* ptr = (char*)&a;
    // char* ptr = static_cast<char*>(&a);
    char* ptr = reinterpret_cast<char*>(&a);

    const int b = 20;
    // int* p1 = reinterpret_cast<int*>(&b);
    int* p1 = const_cast<int*>(&b);
}

// 基本类型 -> 用户自定义类型
void print(const Integer& a) {}
void test1() {
    Integer a1{10};
    Integer a2 = 5;

    print(5);

    a1 = 20;
    std::cout << a1.GetValue() << "\n";
}

// 用户自定义类型 -> 基本类型
void test2() {
    Integer a1{20};
    int x = static_cast<int>(a1);
    std::cout << "x: " << x << "\n";
}

int main() {
    // test1();
    test2();

    return 0;
}
