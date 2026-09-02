/*
 * PROJECT : EXERCISES
 * FILE    : 12.range_based_for_loop.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-09-02
 * BRIEF   : 基于范围的for循环
 */
#include <iostream>

int main() {
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

    for (const auto& x : arr) {
        std::cout << x << " ";
    }
    std::cout << "\n";

    // 基于范围的for循环遍历初始化列表
    for (const auto& var : {10, 9, 8, 7, 6, 5}) {
        std::cout << var << " ";
    }
    std::cout << "\n";
}
