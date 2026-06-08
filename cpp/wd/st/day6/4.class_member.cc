/*
 * PROJECT : DAY6
 * FILE    : 4.class_member.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-06-08
 * BRIEF   : 类数据成员 一个类作为自己的数据成员
 */

#include <iostream>

using std::cout;
using std::endl;

class A {
public:
    A(int a)
        : m_a{a} {
        cout << "A(int)" << endl;
    }

    ~A() { cout << "~A()" << endl; }

    int get() const { return m_a; }

private:
    int m_a = 10;
};

class B {
public:
    B(int b)
        : m_b{b} {
        cout << "B(int)" << endl;
    }
    ~B() { cout << "~B()" << endl; }

    int get() const { return m_b; }

private:
    int m_b = 20;
};

class C {
public:
    // 当A类和B类都有了自己的构造函数
    // 那么编译器不会再为其生成一个默认的无参构造函数
    C(int a, int b)
        : m_a{a},
          m_b{b} {
        cout << "C()" << endl;
    }
    ~C() { cout << "~C()" << endl; }

    // print函数是const限定的，那么this指针就是一个指向常量的常量指针
    // 那么指向的C对象中的m_a和m_b也是一个常对象，但是A类和B类中的
    // get方法是一个普通成员函数，且对应的this只是一个常量指针，不可以接收
    // 常对象的地址，因此是不允许的，只需要将其二者的get方法改为const成员方法即可
    void print() const { cout << "m_a: " << this->m_a.get() << "\nm_b: " << m_b.get() << endl; }

private:
    A m_a;
    B m_b;
};

void test1() {
    C c1{10, 20};
    c1.print();
}

int main() {
    test1();

    return 0;
}
