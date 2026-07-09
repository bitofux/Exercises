/*
 * PROJECT : DAY13
 * FILE    : 4.inherit_override.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-07-08
 * BRIEF   : 继承下的重写
 */
#include <iostream>

namespace over_ride {
class Human {
public:
    virtual void show() { std::cout << "Human::show()" << std::endl; }
};

class Man : public Human {
public:
     void show()override { std::cout << "Man::show()" << std::endl;}
};

// 测试派生类中重写的虚函数是否成功 返回值 函数参数都相同
void test() {
    Man m1;
    Human& h1{m1};
    h1.show();
}
};  // namespace over_ride

int main() {
    over_ride::test();
    return 0;
}
