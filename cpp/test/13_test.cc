/*
 * PROJECT : EXERCISES
 * FILE    : 13_test.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-06-07
 * BRIEF   : 二进制数据
 */

#include <bitset>
#include <climits>
#include <cstddef>
#include <iostream>

int main() {
    signed int b = -0b10001000;

    std::cout << "b: " << b << "\n";
    std::cout << std::bitset<sizeof(b) * CHAR_BIT>(b) << "\n";
}
