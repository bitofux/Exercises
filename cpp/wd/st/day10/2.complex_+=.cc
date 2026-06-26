/*
 * PROJECT : DAY10
 * FILE    : 2.complex_+=.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-06-26
 * BRIEF   : complex类的+=运算符重载
 */
#include <iostream>
#include <istream>
#include <ostream>

class Complex {
public:
    Complex() = default;
    Complex(int real, int image)
        : real_{real},
          image_{image} {}

    // +=运算符重载 -> 成员函数形式
    Complex& operator+=(const Complex& c1) {
        this->real_ += c1.real_;
        this->image_ += c1.image_;
        return *this;
    }

private:
    friend Complex operator+(const Complex& c1, const Complex& c2);
    friend std::ostream& operator<<(std::ostream& os, const Complex& c1);
    friend std::istream& operator>>(std::istream& is, Complex& c1);
    int real_;
    int image_;
};

Complex operator+(const Complex& c1, const Complex& c2) {
    return Complex{c1.real_ + c2.real_, c1.image_ + c2.image_};
}
std::ostream& operator<<(std::ostream& os, const Complex& c1) {
    os << "(" << c1.real_ << "," << c1.image_ << ")";
    return os;
}
std::istream& operator>>(std::istream& is, Complex& c1) {
    is >> c1.real_ >> c1.image_;
    return is;
}

void test() {
    Complex c1{2, 3};
    Complex c2{3, 6};

    std::cout << "c1: " << c1 << std::endl;
    std::cout << "c1 += c2: " << (c1 += c2) << std::endl;
    std::cout << "c1: " << c1 << std::endl;
}

int main() {
    test();

    return 0;
}
