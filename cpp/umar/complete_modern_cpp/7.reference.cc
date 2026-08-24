/*
 * PROJECT : EXERCISES
 * FILE    : 7.reference.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-08-24
 * BRIEF   : 引用
 */
#include <iostream>

int main() {
    using namespace std;
    int x = 10;
    // 引用
    int& ref = x;

    int y = 20;
    ref = y;

    cout << "x: " << x << std::endl;
    cout << "ref: " << ref << std::endl;
}
