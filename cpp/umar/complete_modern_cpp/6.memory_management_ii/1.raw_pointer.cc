/*
 * PROJECT : EXERCISES
 * FILE    : 1.raw_pointer.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-10-18
 * BRIEF   : 原始指针
 */

#include "integer.hpp"

void display(Integer* p) {
    if (!p) {
        return;
    }
    std::cout << p->GetValue() << "\n";
}

Integer* get_pointer(int value) {
    Integer* p = new Integer{value};
    return p;
}

void operate(int value) {
    Integer* p = get_pointer(value);
    if (nullptr == p) {
        p = new Integer{value};
    }
    p->SetValue(20);
    delete p;

    // p = new Integer{};
    // *p = __LINE__;
    display(p);
    delete p;
}

int main() {
    operate(100);

    return 0;
}
