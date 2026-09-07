/*
 * PROJECT : EXERCISES
 * FILE    : 13.function_overloading.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-09-07
 * BRIEF   : 函数重载
 */
#include <iostream>

int add(int a, int b) { return a + b; }

double add(double a, double b) { return a + b; }

// double addDouble(double a,double b) {
//     return a + b;
// }

extern "C" {
void print(int& ptr) {}
void print(const int& ptr) {}
}
int main() {
    int a = 10, b = 20;
    int result = add(a, b);
    std::cout << result << std::endl;

    // std::cout << addDouble(10.2, 20.2);
    std::cout << add(10.2, 20.2);

    return 0;
}
