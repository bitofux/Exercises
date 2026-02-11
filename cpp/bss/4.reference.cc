/*
 * PROJECT : EXERCISES
 * FILE    : 4.reference.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-02-11
 * BRIEF   : 引用
 */
#include <iostream>

int main() {
    // 1. 普通对象引用
    int a = 10;
    int& ref = a;
    std::cout << "&a: " << (void*)&a << "\n";
    std::cout << "&ref: " << (void*)&ref << "\n";

    // 2.对指针的引用
    int* ptr = &a;
    int*& ptr_ref = ptr;
    std::cout << "&ptr: " << (void*)&ptr << "\n";
    std::cout << "&ptr_ref: " << (void*)&ptr_ref << "\n";

    // 3. 对数组的引用
    int arr[10]{0};
    int (&ref_arr)[10] = arr;
    std::cout << "arr: " << (void*)arr << "\n";
    std::cout << "ref_arr: " << (void*)ref_arr << "\n";

    return 0;
}
