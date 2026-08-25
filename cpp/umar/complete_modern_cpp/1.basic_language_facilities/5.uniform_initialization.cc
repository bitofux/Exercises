/*
 * PROJECT : EXERCISES
 * FILE    : 5.uniform_initialization.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-08-24
 * BRIEF   : 统一初始化
 */
#include <iostream>
#include <string>

// C++11 之前
void test() {
    // 未初始化
    int a1;
    // 使用 =
    int a2 = 0;
    // 直接初始化
    int a3(5);

    std::string s1;
    std::string s2("C++");

    char d1[8];
    char d2[8] = {0};
    char d3[8] = {'a', 'b', 'c', 'd'};  // 聚合初始化
    char d4[8] = "abcde";
}

// C++11 
void test1() {
    // 值初始化
    int a1 {};
    // 直接初始化
    int a2 {5};

    std::string {"hello"};

    char ch[8]{};
    char ch1[8]{"hello"};

    int* p1 = new int{};
    int* p2 = new int{5};

    char *ch3 {new char{'a'}};

    // 这看着确实有一些别扭 不够简洁明了
    char *ch4 {new char[8]{"hello"}};

    // 这看着好多了
    char *ch5 = new char[8]{"world"};
}
