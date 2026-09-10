/*
 * PROJECT : EXERCISES
 * FILE    : 4.new_delete_operator_one.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-09-10
 * BRIEF   : new 和 delete 操作符
 */
#include <cstdlib>
#include <iostream>

int main() {
    int* ptr = new int(20);
    *ptr = 10;
    std::cout << "*ptr: " << *ptr << std::endl;

    delete ptr;
    ptr = nullptr;

    return 0;
}
