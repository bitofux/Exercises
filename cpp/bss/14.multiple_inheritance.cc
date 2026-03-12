/*
 * PROJECT : EXERCISES
 * FILE    : 14.multiple_inheritance.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-03-12
 * BRIEF   : 多重继承
 */
#include <iostream>

class base1 {
public:
    base1() { std::cout << "base1()\n"; }
    ~base1() { std::cout << "~base1()\n"; }

    int n;
};

class base2 {
public:
    base2() { std::cout << "base2()\n"; }
    ~base2() { std::cout << "base2()\n"; }

    int n;
};

// 多重继承
class derived : public base1, public base2 {
public:
    derived() { std::cout << "derived()\n"; }
    ~derived() { std::cout << "~derived()\n"; }
};

void test1() {
    derived d1;
    // d1.n = 20; 会造成二义性
    d1.base1::n = 20;
    d1.base2::n = 10;
}
