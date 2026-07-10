/*
 * PROJECT : DAY13
 * FILE    : 6.diamon_inherit.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-07-10
 * BRIEF   : 钻石继承带来的二义性以及如何解决
 */
#include <cstdint>
#include <iostream>

namespace diamon {
class Z {
public:
    Z() { std::cout << "Z()" << std::endl; }
    ~Z() { std::cout << "~Z()" << std::endl; }
    void func() { std::cout << "Z::func()" << std::endl; }
    int z_;
};
class A : public Z {
public:
    A() { std::cout << "A()" << std::endl; }
    ~A() { std::cout << "~A()" << std::endl; }

    void func() { std::cout << "A::func()" << std::endl; }
private:
    int a_;
};

class B : public Z {
public:
    B() { std::cout << "B()" << std::endl; }
    ~B() { std::cout << "~B()" << std::endl; }

    void func() { std::cout << "B::func()" << std::endl; }

private:
    int b_;
};

class C : public A, public B {
public:
    C() { std::cout << "C()" << std::endl; }
    ~C() { std::cout << "~C()" << "\n"; }

private:
    int c_;
};

// 钻石继承带来的二义性
void test() {
    C c;
    // C.func();
    // 产生二义性，在C类型的c对象中，找到多个基类子对象的z_数据成员，从A->Z B->Z
    // std::cout << c.z_ << std::endl;
}
}  // namespace diamon
namespace diamon_solve {
class Z {
public:
    Z() { std::cout << "Z()" << std::endl; }
    ~Z() { std::cout << "~Z()" << std::endl; }
    void func() { std::cout << "Z::func()" << std::endl; }
    int z_;
};

// 虚拟继承
class A : virtual public Z {
public:
    A() { std::cout << "A()" << std::endl; }
    ~A() { std::cout << "~A()" << std::endl; }

    void func() { std::cout << "A::func()" << std::endl; }
private:
    int a_;
};

// 虚拟继承
class B : virtual public Z {
public:
    B() { std::cout << "B()" << std::endl; }
    ~B() { std::cout << "~B()" << std::endl; }

    void func() { std::cout << "B::func()" << std::endl; }

private:
    int b_;
};

class C : public A, public B {
public:
    C() { std::cout << "C()" << std::endl; }
    ~C() { std::cout << "~C()" << "\n"; }

private:
    int c_;
};

// 测试B对象中的虚基指针
void test() {
    B b;
    std::cout << "sizeof b: " << sizeof(b) << std::endl;
    uint64_t ptr = *((uint64_t*)(*((uint64_t*)&(b))) - 3);

    std::cout << ptr << std::endl;
}

}  // namespace diamon

int main() {
    diamon_solve::test();

    return 0;
}
