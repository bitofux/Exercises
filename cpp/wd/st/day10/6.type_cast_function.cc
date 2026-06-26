/*
 * PROJECT : DAY10
 * FILE    : 6.type_cast_function.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-06-26
 * BRIEF   : 类型转换函数
 */
#include <iostream>

class B;
class A {
public:
    explicit A(int data)
        : data_{data} {}

    void show() const { std::cout << "data: " << data_ << std::endl; }
    // 赋值运算符
    A& operator=(int value) {
        data_ = value;
        return *this;
    }

    // 赋值运算符
    A& operator=(const B& rhs);
    // 到A类型的转换
    operator B();

    friend class B;

private:
    int data_;
};

class B {
public:
    explicit B(float fl)
        : fl_{fl} {}

    B(const A& rhs)
        : fl_{static_cast<float>(rhs.data_)} {
        std::cout << "B(const A& rhs)\n";
    }

    B& operator=(const A& rhs) {
        std::cout << "B::operator=(const A& rhs)\n";
        this->fl_ = static_cast<float>(rhs.data_);
        return *this;
    }
    // 到bool类型的转换
    operator bool() { return fl_; }

    void show() const { std::cout << "fl: " << fl_ << std::endl; }

private:
    float fl_;
};

A::operator B() {
    std::cout << "A::operator B()\n";
    return B{static_cast<float>(data_)};
}

// 内置类型 -> 自定义类型
// 由于内置类型是无法设置构造函数的，因此，只能从自定义类型入手
void test() {
    // A a1 = 20; //
    // 编译器找到A类中的带有int类型的构造函数，将20作为参数，构造一个临时对象，赋值给a1
    // 若不想隐式转换，将此构造函数带有explicit

    // B b1 = 3.14f; // 同理
    A a1{20};
    a1.show();
    a1 =
        100;  // 由于20是内置类型，自定义不了什么，这又是赋值运算符，因此可以对A类的运算符重载函数下手
    a1.show();
}

// 自定义 -> 内置类型
// 只要牵扯到内置类型，内置类型动不了手的，从自定义下手
void test1() {
    B b1{100};

    // B -> bool 最常见的就是这个了，文件输入、字符串、通用流都有对bool类型的转换
    bool bo = b1;
    std::cout << "bo: " << bo << std::endl;
}

// 自定义 -> 自定义
// 这就显的很灵活了
void test3() {
    // 从构造函数上做手脚
    A a1{300};
    B b1{400.1f};

    // A -> B
    // 1. 由A的类型转换到B，你可以将B看到是内置类型，这时候就是在A类中写出类似operator
    // bool的成员函数
    // 2. 在A中定义一个特殊的构造函数，参数B类型的即可
    // 3. 在A中对赋值运算符重载函数动手脚
    b1 = a1;
    b1.show();
}
int main() {
    // test();
    // test1();
    test3();

    return 0;
}
