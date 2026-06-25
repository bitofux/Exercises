/*
 * PROJECT : DAY9
 * FILE    : 4.friend_class.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-06-25
 * BRIEF   : 当B类中的所有成员函数想要访问A类中的私有数据成员的时候，可在A中将B类设为友元类
 */
#include <iostream>

class A {
public:
    A(int data, const std::string name)
        : data_{data},
          name_{name} {}

private:
    // 将B设置为友元类
    friend class B;
    int data_;
    std::string name_;
};

class B {
public:
    B(int data, const std::string name)
        : data_{data},
          name_{name} {}

    void test(const A& a1) const {
        std::cout << "a1.name: " << a1.name_ << "\na1.data: " << a1.data_ << std::endl;
    }

    static void test1(const A& a2) {
        std::cout << "a2.name: " << a2.name_ << "\na2.data: " << a2.data_ << std::endl;
    }

private:
    int data_;
    std::string name_;
};

int main() {
    A a1{10, "a1"};
    B b1{20, "b1"};

    b1.test(a1);
    B::test1(a1);
}
