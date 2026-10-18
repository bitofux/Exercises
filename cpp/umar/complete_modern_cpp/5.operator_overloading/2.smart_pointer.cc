/*
 * PROJECT : EXERCISES
 * FILE    : 2.smart_pointer.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-10-14
 * BRIEF   : 简单了解智能指针
 */

#include <iostream>

#include "integer.hpp"

class IntPtr {
private:
    Integer* ptr_;

public:
    IntPtr(Integer* p)
        : ptr_{p} {}
    ~IntPtr() { delete ptr_; }

    // -> 运算符重载
    Integer* operator->() { return ptr_; }

    // * 运算符重载
    Integer& operator*() { return *ptr_; }
};

void CreateInteger() {
    // Integer* p = new Integer{10};
    IntPtr p = new Integer{10};
    p->SetValue(3);
    std::cout << (*p).GetValue() << std::endl;

    // delete p;
}

int main() {
    CreateInteger();

    return 0;
}
