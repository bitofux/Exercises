/****************************************************
 * @file    05_test.cc
 * @brief   new的几种方式
 * @author  bitofux
 * @date    2025-09-05
 ****************************************************/
#include <iostream>
#include <new>

int main() {
    int* ptr{new int{20}};
    std::cout << "*ptr: " << *ptr << "\n";

    const int* ptr1{new int{30}};
    std::cout << "*ptr1: " << *ptr1 << "\n";

    int* ptr2{new (std::nothrow) int{40}};
    std::cout << "*ptr2: " << *ptr2 << "\n";

    int* ptr3{(int*)malloc(sizeof(int))};
    if (ptr3 == nullptr) {
        return -1;
    }
    int* ptr4{new (ptr3) int{60}};
    std::cout << "*ptr4: " << *ptr4 << "\n";

    return 0;
}
