/*
 * PROJECT : DAY14
 * FILE    : 5.virtual_invoke.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-07-15
 * BRIEF   : 虚函数的各种调用
 */
#include <iostream>

using std::cout;
using std::endl;

class GrandFather {
public:
    GrandFather() { cout << "GrandFather()" << endl; }
    ~GrandFather() { cout << "~GrandFather()" << endl; }

    virtual void func1() { cout << "GrandFather::func1()" << endl; }

    virtual void func2() { cout << "GrandFather::func2()" << endl; }

private:
    int m_gf;
};

class Father : public GrandFather {
public:
    Father() {
        func1();
        cout << "Father()" << endl;
    }
    ~Father() {
        func2();
        cout << "~Father()" << endl;
    }

private:
    int m_f;
};

class Son : public Father {
public:
    Son() { cout << "Son()" << endl; }
    ~Son() { cout << "~Son()" << endl; }
    void func1() override { cout << "Son::func1" << endl; }
    void func2() override { cout << "Son::func2" << endl; }

private:
    int m_s;
};

void test() {
    // 1. GrandFather()
    // 2. GrandFather::func1;
    // 3. Father()
    // 4. Son()
    Son son;
}
// 1. ~Son()
// 2. GrandFather::func2()
// 3. ~Father()
// 4. ~GrandFather()

int main() {
    test();

    return 0;
}
