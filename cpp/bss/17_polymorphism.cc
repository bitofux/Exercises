/*
 * PROJECT : EXERCISES
 * FILE    : 17_polymorphism.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-03-13
 * BRIEF   : 多态与协变返回类型(打破虚函数一模一样的规则)
 */
#include <iostream>

class base {
public:
    base() { std::cout << "base()\n"; }
    ~base() { std::cout << "~base()\n"; }
    virtual void show() const { std::cout << "base->show()\n"; }

    virtual base& print() {
        std::cout << "base->print()\n";
        return *this;
    }
};

class derived : public base {
public:
    derived() { std::cout << "derived()\n"; }
    ~derived() { std::cout << "~derived()\n"; }
    // 一模一样的规则 重写
    void show() const override { std::cout << "derived->show()\n"; }

    // 协变返回类型
    derived& print() override {
        std::cout << "derived->print()\n";
        return *this;
    }
};

class derived_one : public base {
public:
    derived_one() { std::cout << "derived_one()\n"; }
    ~derived_one() { std::cout << "~derived_one()\n"; }

    void show() const override { std::cout << "derived_one->show()\n"; }
    derived_one& print() override {
        std::cout << "derived_one->print()\n";
        return *this;
    }
};

void test(base& ba) {
    ba.show();
    ba.print();
}

int main() {
    derived d1;
    derived_one d2;
    test(d1);
    test(d2);
    return 0;
}
