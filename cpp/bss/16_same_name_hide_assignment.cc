/*
 * PROJECT : EXERCISES
 * FILE    : 16_same_name_hide_assignment.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-03-13
 * BRIEF   : 同名隐藏与赋值兼容规则
 */
#include <iostream>

class base {
public:
    base() { std::cout << "base()\n"; }
    ~base() { std::cout << "~base()\n"; }

public:
    void show() { std::cout << "base->show()\n"; }

    void show(int data) { std::cout << "base->show(int)\n"; }
};

class derived : public base {
public:
    derived() { std::cout << "derived()\n"; }
    ~derived() { std::cout << "~derived()\n"; }
    int show(double d) {
        std::cout << "d: " << d << "\n";
        return d;
    }

private:
    double d_;
};

int main() {
    // 1. 同名隐藏(是隐藏所有基类的同名函数 不论参数和返回值)
    derived d;
    std::cout << d.show(20.2) << "\n";
    // 2. 兼容赋值：对象切片 子类对象可赋值为基类对象
    base b{d};
    b.show();
    // 3. 兼容赋值：子类对象的地址可赋值为指向基类的指针
    base* ptr{&d};
    ptr->show();  // 静态绑定 调用base类的show函数
    // 4. 兼容赋值：子类对象可初始化基类的引用
    base& ref{d};
    ref.show();
    return 0;
}
