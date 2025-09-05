/****************************************************
 * @file    4_test.cc
 * @brief   const与一级指针、引用的结合
 * @author  bitofux
 * @date    2025-09-05
 ****************************************************/
#include <iostream>

int main() {
    // 通过普通指针的方式
    int* ptr = (int*)0x0018ff44;
    *ptr = 20;
    std::cout << *ptr << "\n";

    // 通过常引用的方式
    int* const& ref = (int*)0x0018ff44;
    *ref = 20;
    std::cout << *ref << "\n";

    // 通过右值引用的方式
    int*&& ref_right = (int*)0x0018ff44;
    *ref_right = 20;
    std::cout << *ref_right << "\n";

    return 0;
}
