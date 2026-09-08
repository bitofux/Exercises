/*
 * PROJECT : EXERCISES
 * FILE    : 15.inline_function.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-09-08
 * BRIEF   : 内联函数
 */
#include <iostream>

// 内联函数
inline int square(int x) { return x * x; }

int main() {
    using namespace std;

    int result = square(10);
    cout << "result: " << result << "\n";
    return 0;
}
