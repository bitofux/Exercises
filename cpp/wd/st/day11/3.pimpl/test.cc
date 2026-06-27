/*
 * PROJECT : DAY11
 * FILE    : test.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-06-27
 * BRIEF   : 测试pimpl
 */
#include "pimpl.hpp"
#include <iostream>

void test() {
    Line line{1, 2, 3, 4};

    line.printLine();
}

int main() {
    test();

    return 0;
}
