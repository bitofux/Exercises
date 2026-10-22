/*
 * PROJECT : EXERCISES
 * FILE    : 1.raw_pointer.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-10-18
 * BRIEF   : unique_ptr 指针
 */

#include <memory>
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

void store(std::unique_ptr<Integer> p) {
    std::cout << "storing date into a file: " << p->GetValue() << "\n";
}
void operate(int value) {
    std::unique_ptr<Integer> p = static_cast<std::unique_ptr<Integer>>(get_pointer(value));
    display(p.get());
    if (nullptr == p) {
        // p = new Integer{value};
        p.reset(new Integer{value});
    }
    p->SetValue(20);
    // delete p;

    p.reset(new Integer{});
    *p = __LINE__;
    display(p.get());

    p = nullptr;
    // delete p;

    store(std::move(p));

    p.reset(new Integer{20});
}

int main() {
    operate(100);

    return 0;
}
