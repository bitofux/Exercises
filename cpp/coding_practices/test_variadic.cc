/*
 * PROJECT : EXERCISES
 * FILE    : test_variadic.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-03-15
 * BRIEF   : 测试可变参数模板
 */
#include <iostream>

/*
 * 一、基础语法*/

// 1. 模板参数包 -> 声明类型
// 这里有一大包未知的类型
template <typename... Args>
// 2. 函数参数包 -> 声明函数形式参数
// 把上面那包类型，具象化一包变量，取名叫args
void test_func(Args&&... args) {
    // 3. 包展开，使用变量
    // 把这包变量解开，算算里面有几个
    std::cout << "我接收到了 " << sizeof...(args) << " 个参数!" << std::endl;
}

void print() { std::cout << "递归结束\n"; }
/*
 * 二、递归打印这一包参数*/
template <typename T, typename... Args>
void print(T first, Args&&... args) {
    std::cout << first << " -> ";
    print(args...);
}

int main() {
    // 一、基础语法测试
    test_func();
    test_func(10);
    test_func(10, 12.12);
    test_func(10, 12.12, 'a');

    // 二、递归打印
    print(10, "bitofux", 20.12, 'a');
}
