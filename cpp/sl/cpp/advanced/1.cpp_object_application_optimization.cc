/*
 * PROJECT : EXERCISES
 * FILE    : 1.cpp_object_application_optimization.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-08-01
 * BRIEF   : C++对象应用优化
 */
#include <iostream>

class Test {
public:
    Test(int a = 10)
        : a_{a} {
        std::cout << "Test(int)" << std::endl;
    }
    ~Test() { std::cout << "~Test()" << std::endl; }

    Test(const Test& other)
        : a_{other.a_} {
        std::cout << "Test(const Test&)" << std::endl;
    }
    Test& operator=(const Test& others) {
        this->a_ = others.a_;
        std::cout << "operator=(const Test&)" << std::endl;

        return *this;
    }

private:
    int a_;
};

void func(Test t1) { }

Test func1() {
    return Test{20};
}
int main() {
    // Test t1;
    // Test t2{t1};
    // Test t3 = t1;
    //
    // Test t4 = Test{20};

    // func(Test{10});

    func1();

    std::cout << "---------------------------" << std::endl;
    return 0;
}
