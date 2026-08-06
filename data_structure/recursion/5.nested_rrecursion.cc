/*
 * PROJECT : EXERCISES
 * FILE    : 5.nested_rrecursion.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-08-06
 * BRIEF   : 嵌套递归
 */
#include <iostream>

int func(int n) {
    if (n > 100) {
        return n - 10;
    } else {
        return func(func(n + 11));
    }
}

int main() {
    func(95);

    return 0;
}
