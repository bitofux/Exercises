/*
 * PROJECT : EXERCISES
 * FILE    : 13.Derived_class_constructor_destructor.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-03-11
 * BRIEF   : 派生类的构造函数与析构函数的顺序
 *           构造函数：
 *              1. 先按照继承的顺序调用基类的构造函数构造基类子对象
 *              2. 再构造派生类的数据成员(若还是类类型，则调用其指定的构造函数)
 *              3. 再执行派生类构造函数内的执行语句
 *           析构函数：
 *              1. 按照构造函数入栈的相反的顺序进行输出
 */
#include <iostream>

using namespace std;

class base1 {
public:
    base1() { std::cout << "base1()\n"; }
    ~base1() { std::cout << "~base1()\n"; }
};
class base2 {
public:
    base2() { std::cout << "base2()\n"; }
    ~base2() { std::cout << "~base2()\n"; }
};
class base3 {
public:
    base3() { std::cout << "base3()\n"; }
    ~base3() { std::cout << "~base3()\n"; }
};

class derived : public base2, public base3 {
public:
    derived() { std::cout << "derived()\n"; }
    ~derived() { std::cout << "~derived()\n"; }

private:
    base1 one;
    base2 two;
};

int main() {
    derived d;

    return 0;
}
