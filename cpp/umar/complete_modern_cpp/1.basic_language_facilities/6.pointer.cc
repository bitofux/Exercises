/*
 * PROJECT : EXERCISES
 * FILE    : 6.pointer.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-08-24
 * BRIEF   : 指针
 */
#include <iostream>

int main() {
    int var = 10;
    int* ptr1 = &var;
    std::cout << "&var: " << &var << std::endl;
    std::cout << "ptr1: " << ptr1 << std::endl;

    *ptr1 = 20;
    std::cout << "var: " << var << std::endl;
    std::cout << "*ptr1: " << *ptr1 << std::endl;

    // 空指针
    // int* ptr2 = nullptr;
    // *ptr2 = 30;
    // std::cout << "*ptr2: " << *ptr2 << std::endl;

    // 野指针
    // int* ptr3;
    // *ptr3 = 40;
    // std::cout << "*ptr3: " << *ptr3 << std::endl;

    // void 指针
    void* ptr4 = &var;
    std::cout << "*ptr4: " << *(int*)ptr4 << std::endl;

    return 0;
}
