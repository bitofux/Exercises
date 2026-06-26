/*
 * PROJECT : DAY10
 * FILE    : 5.callable_entity.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-06-26
 * BRIEF   : 可调用实体
 *             1. 普通函数
 *             2. 普通函数指针
 *             3. 成员函数
 *             4. 成员函数指针
 *             5. 静态成员函数
 *             6. 静态成员函数指针
 *             7. lambda
 *             8. functor
 */
#include <iostream>
#include <string>
#include <type_traits>

// 1. 普通函数和普通函数指针
void print() { std::cout << "i am regular function"; }
// 测试普通函数指针
void test1() {
    // 定义一个接收print函数地址的指针类型
    using F = void (*)();

    // 定义一个函数指针
    F f1 = print;

    // 利用函数指针调用
    f1();
}

class Human {
public:
    Human(const std::string& name, int age)
        : name_{name},
          age_{age} {}

    // 函数调用()运算符重载
    void operator()(int value) {
        std::cout << "name: " << name_ << "\n" << "age: " << age_ << std::endl;
    }

    void show(int value) { std::cout << "nonconst value: " << value << std::endl; }
    void show(int value) const { std::cout << "const value: " << value << std::endl; }

    static int GetAge() { return count; }

private:
    std::string name_;
    int age_;
    static int count;
};
int Human::count = 100;
// 测试成员函数指针
void test2() {
    // 成员函数是位于Human类内部的，那么需要带上Human和作用域限定符
    // 这样的声明方式，是直接指定了Human类中的，也可以只写出函数的类型，具体哪个类可以在定义
    // 成员指针的时候在写。
    using F = void (Human::*)(int);
    using Fc = void (Human::*)(int) const;

    // 使用F定义一个非常成员函数指针类型的变量
    F ptr = &Human::show;
    // 使用Fc定义一个常成员函数指针类型的变量
    Fc ptr1 = &Human::show;

    // 使用这些成员函数指针变量调用的时候，需要带上对象
    Human h1{"bitofux", 20};

    // 使用非常对象调用非常成员函数指针，可以
    (h1.*ptr)(20);

    // 定义一个指向Human的指针
    Human* h1_ptr = &h1;
    // (h1_ptr->*ptr)(40);

    // 使用常对象调用常成员函数指针(精确匹配)
    const Human h2{"tafu", 30};
    (h2.*ptr1)(60);

    // 特殊情况：若成员函数指针的值为nullptr，那么调用的这个成员函数中若没有访问数据成员
    // 那么是可以调用的，否则不可以，因为访问数据成员是一定需要依赖对象状态的
    ptr = nullptr;
    (h1.*ptr)(20);
}

// 测试functor
void test3() {
    Human h1{"bitofux", 20};
    h1(20);  // h1.operator()(20);
}

// 测试静态成员函数
void test4() {
    using F = int (*)();

    // 定义一个成员函数指针
    F f1 = &Human::GetAge;
    std::cout << f1() << std::endl;
}

// lambda
void test5() {
    auto&& var = []() { std::cout << "Hello Lambda\n"; };

    var();
}
int main() {
    // test1();

    // test4();
    // test5();
    test2();
    return 0;
}
