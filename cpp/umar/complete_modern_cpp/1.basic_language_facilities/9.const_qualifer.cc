/*
 * PROJECT : EXERCISES
 * FILE    : 9.const_qualifer.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-08-25
 * BRIEF   : const 限定符
 */
#include <iostream>

int main() {
    using namespace std;
    const float PI = 3.14f;
    float radius = 0;
    std::cin >> radius;

    float area = PI * radius * radius;
    float circumference = PI * 2 * radius;

    std::cout << "area: " << area << std::endl;
    std::cout << "circumference: " << circumference << std::endl;
}
