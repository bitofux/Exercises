/*
 * PROJECT : EXERCISES
 * FILE    : 1.integer.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-10-02
 * BRIEF   :
 */
#include <iostream>
#include <utility>

class Integer {
private:
    int* ptr_;

public:
    // 无参构造函数
    Integer() {
        std::cout << "Integer()\n";
        ptr_ = new int{0};
    }
    // 参数化构造函数
    Integer(int value) {
        std::cout << "Integer(int)\n";
        ptr_ = new int{value};
    }
    // 拷贝构造函数
    Integer(const Integer& other) {
        std::cout << "Integer(const Integer&)\n";
        ptr_ = new int{*other.ptr_};
    }
    // 拷贝赋值运算符重载函数
    Integer& operator=(const Integer& other) {
        std::cout << "operator=(const Integer&)\n";
        if (this != &other) {
            *ptr_ = *other.ptr_;
        }
        return *this;
    }
    // 移动构造函数
    Integer(Integer&& other) {
        ptr_ = other.ptr_;
        other.ptr_ = nullptr;
        std::cout << "Integer(Integer&&)\n";
    }
    // 移动赋值运算符重载函数
    Integer& operator=(Integer&& other) {
        std::cout << "operator=(Integer&&)\n";
        if (this != &other) {
            delete ptr_;
            ptr_ = other.ptr_;
            other.ptr_ = nullptr;
        }

        return *this;
    }
    int GetValue() const { return *ptr_; }
    void SetValue(int value) { *ptr_ = value; }
    const int* GetData() const { return ptr_; }
    ~Integer() {
        std::cout << "~Integer()\n";
        delete ptr_;
    }
};

class Number {
private:
    Integer i_value_;

public:
    Number(int value)
        : i_value_{value} {}

    // Number(const Number& obj) = default;
    // Number& operator=(const Number& obj) = default;
    // Number(Number&& obj) = default;
    // Number& operator=(Number&&) = default;
    ~Number() = default;
};

Integer add(Integer& a, Integer& b) {
    Integer tmp;
    tmp.SetValue(a.GetValue() + b.GetValue());

    return tmp;
}

Integer add(int a, int b) {
    // Integer temp{a + b};
    return Integer{a + b};
}

void test() {
    Integer a = add(3, 4);
    return;
}

void test1() {
    Integer a{3};
    auto b{std::move(a)};
}

Number CreateNumber(int value) {
    Number n{value};
    return n;
}
int main() {
#if 0
    Number n1{10};
    auto n2{n1};

    n2 = n1;

    auto n3{CreateNumber(10)};
    n3 = CreateNumber(20);

    return 0;
#endif
    test1();
}
