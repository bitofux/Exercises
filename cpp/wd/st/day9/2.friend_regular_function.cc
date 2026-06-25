/*
 * PROJECT : DAY9
 * FILE    : 2.friend_regular_function.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-06-25
 * BRIEF   : 普通函数访问类中私有成员 -- 友元普通函数
 */
#include <iostream>
#include <string>

class Human {
public:
    Human(const std::string& name, const int age)
        : name_{name},
          age_{age} {}

private:
    // 友元普通函数
    friend void test(const Human& h1);
    std::string name_;
    int age_;
};

// 现在有一个普通函数需要访问Human类中的私有数据成员
void test(const Human& h1) {
    std::cout << "name: " << h1.name_ << "\nage: " << h1.age_ << std::endl;
}

int main() {
    Human h1{"bitofux", 28};
    test(h1);

    return 0;
}
