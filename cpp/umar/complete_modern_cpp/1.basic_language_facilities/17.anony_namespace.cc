/*
 * PROJECT : EXERCISES
 * FILE    : 17.anony_namespace.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-09-08
 * BRIEF   : 匿名命名空间
 */
#include <iostream>

namespace {
int add(int a, int b) { return a + b; }
}  // namespace

int main() {
    std::cout << add(10, 20) << std::endl;

    return 0;
}
