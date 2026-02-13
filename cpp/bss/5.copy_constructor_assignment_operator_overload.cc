/*
 * PROJECT : EXERCISES
 * FILE    : 5.copy_constructor_assignment_operator_overload.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-02-12
 * BRIEF   : 拷贝构造函数和赋值运算符重载函数
 */

#include <iostream>

class Human {
public:
    Human() { std::cout << "Human()-> " << this << "\n"; }
    Human(const int age)
        : age_{age} {
        std::cout << "Human(int)-> " << this << "\n";
    }
    // 拷贝构造函数
    Human(const Human& other)
        : age_{other.age_} {
        std::cout << "Human(const Human& other)-> " << this << "\n";
    }
    // 赋值运算符重载函数
    Human& operator=(const Human& other) {
        std::cout << "operator=(const Human&)" << this << " <- " << &other << "\n";
        // 防止自复制
        if (this != &other) {
            this->age_ = other.age_;
        }
        return *this;
    }
    // 析构函数
    ~Human() { std::cout << "~Human-> " << this << "\n"; }

private:
    int age_;
};

int main() {
    // 调用单个参数的构造函数
    Human h1{20};
    // 调用拷贝构造函数
    Human h2{h1};
    // 调用无参构造函数
    Human h3;
    // 调用赋值运算符重载函数
    h3 = h1;


    return 0;
}
