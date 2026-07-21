/*
 * PROJECT : EXERCISES
 * FILE    : virtual_inherit_virtual_func.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-07-21
 * BRIEF   : 虚继承下的虚函数
 */
#include <cstddef>
#include <cstdint>
#include <iostream>

using std::cout;
using std::endl;

class A {
public:
    A(long a = 10)
        : a_{a} {
        cout << "A(int)" << endl;
    }

    virtual void func() { cout << "A::func()" << endl; }

private:
    long a_;
};
class B : virtual public A {
public:
    B(long b = 10)
        : b_{b} {
        cout << "B(int)" << endl;
    }

    // void func() override { cout << "B::func()" << endl; }

private:
    long b_;
};
class C : virtual public A {
public:
    C(long c = 10)
        : c_{c} {
        cout << "C(int)" << endl;
    }

    // void func() override { cout << "C::func()" << endl; }

private:
    long c_;
};

class D : public B, public C {
public:
    D(long d = 40)
        : d_{d} {}
    // void func() override { cout << "D::func()" << endl; }

private:
    long d_;
};

int main() {
    // D d1;

    // auto* b_ptr = reinterpret_cast<std::uintptr_t*>(&d1);
    //
    // auto* c_ptr = reinterpret_cast<std::ptrdiff_t*>(b_ptr + 2);
    //
    // auto* func = reinterpret_cast<void (*)(A*)>(reinterpret_cast<std::uintptr_t*>(b_ptr[0])[0]);
    // func(static_cast<A*>(&d1));
    //
    // cout << "sizeof d1: " << sizeof(d1) << endl;
    A a1;
    B b1;
    C c1;
    cout << "sizeof a1: " << sizeof(a1) << endl;
    cout << "sizeof b1: " << sizeof(b1) << endl;
    cout << "sizeof c1: " << sizeof(c1) << endl;
    D d1;

    A* bp = &d1;

    auto** vptr_address = reinterpret_cast<std::uintptr_t**>(bp);

    std::uintptr_t* vtable = *vptr_address;

    using Func = void (*)(A*);

    auto func = reinterpret_cast<Func>(vtable[0]);

    func(bp);

    B* bbp = &d1;

    cout << ((reinterpret_cast<std::ptrdiff_t**>(bbp))[0])[-3];
    C* ccp = &d1;

    cout << ((reinterpret_cast<std::ptrdiff_t**>(ccp))[0])[-3];

    cout << "sizeof d1: " << sizeof(d1) << endl;
}
