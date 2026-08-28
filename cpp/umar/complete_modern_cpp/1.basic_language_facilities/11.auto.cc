/*
 * PROJECT : EXERCISES
 * FILE    : 11.auto.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-08-28
 * BRIEF   : auto 关键字
 */
#include <iostream>

int get_sum(int i, int j) { return i + j; }

static auto const variable = 100;

void test() {
    // 初始器为字面量
    auto i = 10;
    auto j = 5;

    // 初始化器是一个表达值
    auto sum = i + j;
    auto sum1 = i + 3.4f;

    // 初始化器是一个函数调用
    auto sum2 = get_sum(i, j);
}

void test1() {
    const int var = 10;
    auto var_auto = var;

    // 常引用
    auto& ref_var = var;
    // ref_var = 10;// error

    // 初始化列表仅当花括号初始化器出现在赋值运算符右侧的时候才会被创建
    auto list  = {1,2,3,4};
}

int main() {
    test1();

    return 0;
}
