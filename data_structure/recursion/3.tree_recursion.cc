/*
 * PROJECT : EXERCISES
 * FILE    : 3.tree_recursion.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-08-04
 * BRIEF   : 树递归示例
 */

#include <iostream>

void func(int n) {
    if (n > 0) {
        std::cout << n << " ";
        func(n - 1);
        func(n - 1);
    }
}

int main() {
    int x = 3;

    func(3);
    std::cout << std::endl;

    return 0;
}
