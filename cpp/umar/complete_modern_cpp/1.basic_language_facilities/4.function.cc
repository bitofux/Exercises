/*
 * PROJECT : EXERCISES
 * FILE    : 4.function.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-08-24
 * BRIEF   : 函数
 */
#include <iostream>

#include "4.1.utils.h"

int main() {
    std::cout << "input two nums: ";
    int x, y;
    std::cin >> x >> y;

    int result = add(x, y);
    std::cout << "result: " << result << std::endl;

    print('#');
}
