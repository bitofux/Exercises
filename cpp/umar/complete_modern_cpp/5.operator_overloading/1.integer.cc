/*
 * PROJECT : EXERCISES
 * FILE    : 1.integer.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-10-09
 * BRIEF   : 整数类
 */
#include <iostream>
#include <utility>

class Integer {
private:
    int* ptr_;

public:
    // 默认构造函数
    Integer()
        : ptr_{nullptr} {}
    // 参数化构造函数
    Integer(int value)
        : ptr_{new int{value}} {
        std::cout << "Integer(int)\n";
    }

    // 拷贝构造函数
    Integer(const Integer& other) {
        std::cout << "Integer(const Integer&)\n";
        this->ptr_ = new int{*other.ptr_};
    }
    // 拷贝赋值运算符重载函数
    Integer operator=(const Integer& other) {
        std::cout << "operator=(const Integer&)\n";
        if (this == &other) {
            return *this;
        }
        *this->ptr_ = *other.ptr_;
        return *this;
    }

    // 移动构造函数
    Integer(Integer&& other) {
        std::cout << "Integer(Integer&&)\n";
        this->ptr_ = other.ptr_;
        other.ptr_ = nullptr;
    }
    // 移动赋值运算符重载函数
    Integer operator=(Integer&& other) {
        std::cout << "operator=(integer&&)\n";
        if (this == &other) {
            return *this;
        }
        delete this->ptr_;
        this->ptr_ = other.ptr_;
        other.ptr_ = nullptr;

        return *this;
    }

    // 析构函数
    ~Integer() {
        std::cout << "~Integer()\n";
        delete ptr_;
    }

    void SetValue(int value) {
        if (ptr_ == nullptr) {
            ptr_ = new int{value};
        }
        *ptr_ = value;
    }

    int GetValue() const { return *this->ptr_; }

    Integer operator+(const Integer& other) { return Integer{*this->ptr_ + *other.ptr_}; }
};

Integer operator+(const Integer& a, const Integer& b) {
    return Integer{a.GetValue() + b.GetValue()};
}

int main() {
    Integer a{1}, b{2};
    Integer sum = a + b;

    std::cout << "sum: " << sum.GetValue() << "\n";
}
