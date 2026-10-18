/*
 * PROJECT : EXERCISES
 * FILE    : 3.unique_ptr.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-10-14
 * BRIEF   : uinque_ptr
 */

#include <iostream>
#include <memory>

#include "integer.hpp"

void process(/*std::unique_ptr<Integer>*/ std::shared_ptr<Integer> ptr) {
    std::cout << ptr->GetValue() << "\n";
}
int main() {
    /*std::unique_ptr<Integer>*/ std::shared_ptr<Integer> p{new Integer{3}};
    (*p).SetValue(20);
    std::cout << (*p).GetValue() << "\n";

    // auto p1{std::move(p)};

    process(p);

    if (p.get() == nullptr) {
        std::cout << "True" << std::endl;
    } else {
        std::cout << "False" << std::endl;
    }

    return 0;
}
