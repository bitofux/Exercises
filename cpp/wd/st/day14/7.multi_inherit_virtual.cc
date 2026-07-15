/*
 * PROJECT : DAY14
 * FILE    : 7.multi_inherit_virtual.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-07-15
 * BRIEF   : 多继承下的虚函数
 */
#include <cstddef>
#include <cstdint>
#include <iostream>

using std::cout;
using std::endl;

class Father1 {
public:
    Father1() { cout << "Father1()" << endl; }
    virtual void f() { cout << "Father1::f()" << endl; }

    virtual void g() { cout << "Father1::g()" << endl; }

    virtual void h() { cout << "Father1::h()" << endl; }

private:
    uint64_t m_f1;
};
class Father2 {
public:
    Father2() { cout << "Father2()" << endl; }
    virtual void f() { cout << "Father2::f()" << endl; }

    virtual void g() { cout << "Father2::g()" << endl; }

    virtual void h() { cout << "Father2::h()" << endl; }

private:
    uint64_t m_f2;
};
class Father3 {
public:
    Father3() { cout << "Father3()" << endl; }
    virtual void f() { cout << "Father3::f()" << endl; }

    virtual void g() { cout << "Father3::g()" << endl; }

    virtual void h() { cout << "Father3::h()" << endl; }

private:
    uint64_t m_f3;
};

class Son : public Father1, public Father2, public Father3 {
public:
    Son() { cout << "Son()" << endl; }

    void f() override { cout << "Son::f()" << endl; }

private:
    uint64_t m_s;
};

// 测试三个基类指针指向同一个派生对象时，
// 它们相对于派生对象基地址的偏移量为多少
void test() {
    Son son;

    Father1* f1{&son};
    Father2* f2{&son};
    Father3* f3{&son};

    cout << "offset of f1: " << ((uint8_t*)f1 - (uint8_t*)(&son)) << endl;
    cout << "offset of f2: " << ((uint8_t*)f2 - (uint8_t*)(&son)) << endl;
    cout << "offset of f3: " << ((uint8_t*)f3 - (uint8_t*)(&son)) << endl;
}

// 测试son对象中三个虚函数中的第一个虚函数地址是否是同一个
void test1() {
    Son s;
    // 派生类中的每个基类子对象中的vptr指向的虚函数表中哪个被重写的虚函数的地址不同
    // 因为还存在一个调整this指针的次级虚函数
    cout << "Son::f one ptr: " << (uint64_t*)(*((uint64_t*)(*(uint64_t*)(&s)))) << endl;
    cout << "Son::f two ptr: " << (uint64_t*)(*((uint64_t*)(*(uint64_t*)((uint64_t*)(&s) + 2))))
         << endl;
    cout << "Son::f three ptr: " << (uint64_t*)(*((uint64_t*)(*(uint64_t*)((uint64_t*)(&s) + 4))))
         << endl;

    using func = void (*)();
    func fptr;
    fptr = (func)(uint64_t*)(*((uint64_t*)(*(uint64_t*)(&s))));
    fptr();

    fptr = (func)(uint64_t*)(*((uint64_t*)(*(uint64_t*)((uint64_t*)(&s) + 2))));

    fptr();
    fptr = (func)(uint64_t*)(*((uint64_t*)(*(uint64_t*)((uint64_t*)(&s) + 4))));

    fptr();
}

int main(int argc, char* argv[]) {
    // test();
    test1();
    return 0;
}
