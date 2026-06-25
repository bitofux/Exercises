/*
 * PROJECT : DAY9
 * FILE    : 5.complex+.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-06-25
 * BRIEF   : 复数类中的+运算符重载
 */
#include <iostream>

class Complex {
public:
    Complex(int real, int image)
        : real_{real},
          image_{image} {}
    void show() const { std::cout << "(" << real_ << "," << image_ << ")" << "\n"; }

private:
    friend Complex operator+(const Complex& c1, const Complex& c2);
    int real_;
    int image_;
};

// 普通全局函数重载运算符+
Complex operator+(const Complex& c1, const Complex& c2) {
    return Complex{c1.real_ + c2.real_, c1.image_ + c2.image_};
}

int main() {
    Complex c1{1, 1};
    Complex c2{2, 2};
    Complex c3 = operator+(c1, c2);
    c3.show();

    return 0;
}
