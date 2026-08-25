/*
 * PROJECT : EXERCISES
 * FILE    : 4.1.utils.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-08-24
 * BRIEF   : utils
 */
#include "4.1.utils.h"

#include <iostream>

void print(char ch) {
    for (int i = 0; i < 10; ++i) {
        std::cout << ch;
    }
}

int add(int x, int y) { return x + y; }
