/*
 * PROJECT : EXERCISES
 * FILE    : integer.hpp
 * AUTHOR  : bitofux
 * DATE    : 2026-10-14
 * BRIEF   :
 */

#ifndef EXERCISES_INTEGER_HPP
#define EXERCISES_INTEGER_HPP

#include <iostream>
#include <istream>
#include <ostream>

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
        std::cout << "operator=(const Integer&)" << std::endl;
        if (this != &other) {
            delete this->ptr_;
            this->ptr_ = new int{*other.ptr_};
        }
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
        if (this != &other) {
            delete this->ptr_;
            this->ptr_ = other.ptr_;
            other.ptr_ = nullptr;
        }

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

    // +运算符
    Integer operator+(const Integer& other) { return Integer{*this->ptr_ + *other.ptr_}; }

    // ++前自增运算符
    Integer& operator++() {
        ++(*this->ptr_);
        // 返回自身
        return *this;
    }

    // ++后自增运算符
    Integer operator++(int) {
        Integer temp = *this;
        ++(*this->ptr_);
        return temp;
    }

    // ==运算符
    bool operator==(const Integer& other) const { return (*this->ptr_ == *other.ptr_); }

    // () 运算符
    void operator()() { std::cout << *this->ptr_ << std::endl; }

    // 友元
    friend std::ostream& operator<<(std::ostream& os, const Integer& other);
    friend std::istream& operator>>(std::istream& is, Integer& other);

    // 类型转换操作符函数
    explicit operator int() { return *ptr_; }
};

Integer operator+(int a, const Integer& b) { return Integer{a + b.GetValue()}; }

std::ostream& operator<<(std::ostream& os, const Integer& other) {
    os << *other.ptr_;

    return os;
}

std::istream& operator>>(std::istream& is, Integer& other) {
    is >> *other.ptr_;
    return is;
}

#endif  // EXERCISES_INTEGER_HPP
