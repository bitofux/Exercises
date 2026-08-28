/*
 * PROJECT : EXERCISES
 * FILE    : 10.const_quelifer_compound_type.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-08-28
 * BRIEF   : const与复合类型的结合：尤其是指针和引用
 */
#include <iostream>

// const 与 pointer
void pointer() {
    int var = 10;

    // ptr 指向的对象不可通过指针间接去修改，但可以访问
    int const* ptr = &var;
    std::cout << "*ptr" << *ptr << std::endl;
    // *ptr = 20; // error

    // ptr 指向的对象不可通过指针间接去修改，但可访问
    // ptr本身也是一个独立的变量的，它也不可被修改
    int const* const ptr1 = &var;
    // *ptr1 = 30; // error
    int var1 = 40;
    // ptr1 = &var1; // error

    // ptr2 指向的对象可以通过指针间接去修改和访问，但是ptr2本身不可被修改
    int* const ptr2 = &var1;
    *ptr2 = 50;
    // ptr2 = &var; // error
}

// const 与 ref
void ref() {
    int var = 100;

    // 可通过 ref_var 间接访问(读写皆可)引用的对象
    // 引用本身就不可被修改
    // 这种形式的引用称为左值引用
    int& ref_var = var;

    ref_var = 30;
    std::cout << "ref_var: " << ref_var << std::endl;

    // 常引用：可接收左值和纯右值 不可接收xvalue
    // 不可通过常引用修改引用的对象，但可以读取
    int const& ref_var1 = 10;
    // ref_var1 = 30;
    std::cout << "ref_var1: " << ref_var1 << std::endl;
}

int main() {
    pointer();
    ref();
    return 0;
}
