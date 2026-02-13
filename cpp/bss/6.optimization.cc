/*
 * PROJECT : EXERCISES
 * FILE    : 6.optimization.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-02-12
 * BRIEF   : 一些常见的优化
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

public:
    int get_age() const { return age_; }

private:
    int age_;
};

// 测试一
Human test1(Human other) {
    int var = other.get_age();
    Human tmp{var};
    return tmp;
}
// 测试二
Human test2(const Human& other) {
  int var = other.get_age();
  Human tmp {var};
  return tmp;
}
// 测试三
Human test3(const Human& other) {
  int var = other.get_age();
  return Human{var};
}
int main() {
    Human h1{20};
    Human h2 = test3(h1);
}
