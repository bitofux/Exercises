/*
 * PROJECT : EXERCISES
 * FILE    : 10.function_template.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-03-04
 * BRIEF   : 函数模板的简单理解
 */
#include <iostream>

// 函数模板 -> 是一个模板
template <typename T>
T Max(T arg1, T arg2) {
    return arg1 > arg2 ? arg1 : arg2;
}

int main() {
    // 隐式传递类型参数->类型推导
    std::cout << "max(int): " << Max(10, 20) << "\n";
    std::cout << "max(double): " << Max(10.2, 20.1) << "\n";
    std::cout << "max(char): " << Max('a', 'b') << "\n";
    // 显式传递类型参数
    std::cout << "Max(int): " << Max<int>(10, 20) << "\n";
    std::cout << "Max(double): " << Max<double>(10, 20) << "\n";
    std::cout << "Max(float): " << Max<float>(10, 20) << "\n";

    return 0;
}
