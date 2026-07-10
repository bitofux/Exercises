/*
 * PROJECT : DAY13
 * FILE    : 5.multi_inherit_intro.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-07-10
 * BRIEF   : 多继承的介绍
 */
#include <iostream>

class A {
public:
    A() { std::cout << "A()" << std::endl; }
    ~A() { std::cout << "~A()" << std::endl; }

    void func() { std::cout << "A::func()" << std::endl; }

private:
    int a_;
};

class B {
public:
    B() { std::cout << "B()" << std::endl; }
    ~B() { std::cout << "~B()" << std::endl; }

    void func() { std::cout << "B::func()" << std::endl; }

private:
    int b_;
};

class C : public A, public B {
public:
    C() { std::cout << "C()" << std::endl; }
    ~C() { std::cout << "~C()" << std::endl; }

    // void func() { std::cout << "C::func()" << std::endl; }

private:
    int c_;
};

void test() {
    C c;
    // c.func(); 产生二义性
}

int main() {
    test();

    return 0;
}
