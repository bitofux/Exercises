/*
 * PROJECT : DAY9
 * FILE    : 3.friend_member_function.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-06-25
 * BRIEF   : 一个类中的成员函数想要访问另外一个类中的私有数据成员
 */
#include <iostream>

using std::cout;

class B;
class A {
public:
    A(int data)
        : data_{data} {}

    // 若A中的成员函数访问B类数据成员
    void print_B(const B& b1) const;

private:
    friend class B;
    int data_;
};

class B {
public:
    B(int data)
        : data_{data} {}

    // 访问A中的私有数据成员
    void print_A(const A& a1) const { std::cout << "a1.data: " << a1.data_ << std::endl; }

private:
    // 将B类中的成员函数print_B设置为友元
    friend void A::print_B(const B& b1) const;
    int data_;
};

// 将A类中的print_B成员函数的定义放在class B声明之后，此时B是一个完整的类型
void A::print_B(const B& b1) const { std::cout << "b1.data: " << b1.data_ << std::endl; }

int main() {
    A a1{10};
    B b1{20};
    a1.print_B(b1);
    b1.print_A(a1);

    return 0;
}
