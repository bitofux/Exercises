/*
 * PROJECT : EXERCISES
 * FILE    : test_pwndbg.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-06-08
 * BRIEF   : 测试pwndbg
 */
#include <cstdint>
#include <iostream>
#include <vector>

// 带有虚函数的基类

class Base {
public:
    uint64_t base_val = 0xAAAAAAAA;
    virtual void say_hello() { std::cout << "I am Base\n"; }
    virtual ~Base() { std::cout << "I am ~Base\n"; }
};

class derived : public Base {
public:
    uint64_t derived_val = 0xBBBBBBBB;
    void say_hello() override { std::cout << "I am Derived\n"; }
};

int main() {
    // 1. 探究std::vector的内存布局
    std::vector<uint64_t> magic_num{0x1111, 0x2222, 0x3333};

    // 2. 探究虚函数机制 多态对象的内存布局
    Base* obj = new derived{};
    obj->say_hello();

    delete obj;

    return 0;
}
