/*
 * PROJECT : EXERCISES
 * FILE    : 9.static_const.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-03-04
 * BRIEF   : static成员与const方法
 */
#include <iostream>
#include <string>

class human {
public:
    human(std::string name, int age)
        : name_{name},
          age_(age) {
        ++count_;
        std::cout << "human(std::string,int)\n";
    }
    // 无this指针，不需要对象去激活
    static int get_count() {
        // 静态成员函数不可以访问非静态成员
        // cout << "name: " << name_ << "\n";
        return count_;
    }
    // 有this指针，需要对象去激活
    const std::string& get_name() const { return name_; }
    const int get_age() const { return age_; }

private:
    std::string name_;
    int age_;
    static int count_;
};

int human::count_ = 0;

int main() {
    human h1{"bfx", 20};
    std::cout << human::get_count() << "\n";
    std::cout << "name: " << h1.get_name() << "\n";
    std::cout << "age: " << h1.get_age() << "\n";

    return 0;
}
