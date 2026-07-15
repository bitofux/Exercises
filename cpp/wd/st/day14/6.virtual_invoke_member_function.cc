/*
 * PROJECT : DAY14
 * FILE    : 6.virtual_invoke_member_function.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-07-15
 * BRIEF   : 成员函数中调用虚函数
 */
#include <iostream>

using std::cout;
using std::endl;

class Father {
public:
    Father() { cout << "Father()" << endl; }
    virtual void func() { cout << "Father::func()" << endl; }

    void father_methon1() {
        cout << "Father::father_methon1()\n";
        Father::func();
    }

    void father_methon2() {
        cout << "Father::father_methon2()\n";
        func();
    }
};

class Son : public Father {
public:
    Son() { cout << "Son()" << endl; }

    void func() override { cout << "Son::func()" << endl; }
};

void test() {
    // Father f1;
    // f1.father_methon1();
    // f1.father_methon2();

    Son s1;
    s1.father_methon1();
    s1.father_methon2();
}

int main() {
    test();

    return 0;
}
