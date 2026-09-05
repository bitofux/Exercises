/*
 * PROJECT : EXERCISES
 * FILE    : 12.range_based_for_loop.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-09-02
 * BRIEF   : 基于范围的for循环
 */
#include <iostream>

// 基于范围的for循环的内部实现伪代码
void internal() {
    int arr[5] = {1, 2, 3, 4, 5};
#if 0
    // 获取数组中第一个元素的地址
    int* begin = &arr[0];
    // 获取数组中最后一个元素后一个的地址
    int* end = &arr[5];

    // 定义while循环遍历数组
    while (begin != end) {
        std::cout << *begin << " ";
        ++begin;
    }
#endif
    auto &range = arr;
    // 获取数组中第一个元素的地址
    auto begin = std::begin(arr);

    // 获取数组中最后一个元素后一个的地址
    auto end = std::end(arr);

    for (;begin != end;++begin) {
        auto v = *begin;
        std::cout << v << " ";
    }
}
int main() {
    internal();
#if 0
    // 定义5个元素的数组
    int arr[5] = {1, 2, 3, 4, 5};

    // 使用普通的循环遍历数组
    for (int i = 0; i < 5; ++i) {
        std::cout << "arr[" << i << "]: " << arr[i] << "\n";
    }

    // 基于范围的for循环
    for (int x : arr) {
        std::cout << x << " ";
    }
    std::cout << "\n";

    // arr 是一个左值
    for (const auto& x : arr) {
        std::cout << x << " ";
    }
    std::cout << "\n";

    // 基于范围的for循环遍历初始化列表 -- 纯右值
    for (const auto& var : {10, 9, 8, 7, 6, 5}) {
        std::cout << var << " ";
    }
    std::cout << "\n";
#endif
}
