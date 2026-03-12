/*
 * PROJECT : EXERCISES
 * FILE    : 15.diamond_inheritance.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-03-12
 * BRIEF   : 钻石继承
 */
#include <iostream>

class base0 {
public:
    base0() { std::cout << "base0()\n"; }
    ~base0() { std::cout << "~base0()\n"; }
    int m;
};

class base1 : virtual public base0 {
public:
    base1() { std::cout << "base1()\n"; }
    ~base1() { std::cout << "~base1()\n"; }
    int n;
};

class base2 : virtual public base0 {
public:
    base2() { std::cout << "base2()\n"; }
    ~base2() { std::cout << "~base2()\n"; }
    int n;
};

// 钻石继承
// derived类中的base1与base2中的base0的m不是一个m，地址不同
// 正常的逻辑就是derived继承了base1，base2的话，那么针对base0的数据成员有且只有一份即可
// 采用虚继承，使得base0成为虚基类
class derived : public base1, public base2 {
public:
    derived() { std::cout << "derived()\n"; }
    ~derived() { std::cout << "~derived()\n"; }
};

void test() {
    derived d1;
    return;
}

int main() {
    test();

    return 0;
}
