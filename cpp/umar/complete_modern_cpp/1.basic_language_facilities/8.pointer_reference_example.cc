/*
 * PROJECT : EXERCISES
 * FILE    : 8.pointer_reference_example.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-08-24
 * BRIEF   : 指针和引用示例
 */
#include <iostream>

void swap(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void swap(int& x, int& y) {
    int temp = x;
    x = y;
    y = x;
}

// void print(int* ptr) { std::cout << *ptr << std::endl; }

void print(int& ref) { std::cout << ref << std::endl; }

int main() {
    int x = 10;
    int y = 5;

    int *ptr = new int{6};
    delete ptr;

    // swap(&x, &y);
    // swap(x, y);
    // print(&x);
    print(*ptr);

    // std::cout << "x: " << x << std::endl;
    // std::cout << "y: " << y << std::endl;
}
