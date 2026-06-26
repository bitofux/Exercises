/*
 * PROJECT : EXERCISES
 * FILE    : 1.complex_cout_cin.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-06-26
 * BRIEF   : complex类的<<和>>运算符重载
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
    void print() const { std::cout << "(" << real_ << "," << image_ << ")" << std::endl; }

private:
    friend Complex operator+(const Complex& c1, const Complex& c2);
    friend std::ostream& operator<<(std::ostream& os, const Complex& c1);
    friend std::istream& operator>>(std::istream& is, Complex& c1);
    int real_;
    int image_;
};

// +运算符重载
Complex operator+(const Complex& c1, const Complex& c2) {
    return Complex{c1.real_ + c2.real_, c1.image_ + c2.image_};
}

// 测试+运算符重载
void test() {
    Complex c1{1, 2};
    Complex c2{2, 3};
    Complex c3 = c1 + c2;
    c3.print();
}

// << 运算符重载和测试
std::ostream& operator<<(std::ostream& os, const Complex& c1) {
    os << "(" << c1.real_ << "," << c1.image_ << ")";
    return os;
}

void test2() {
    Complex c1{1, 2};
    Complex c2{3, 3};
    Complex c3 = c1 + c2;
    std::cout << c3 << std::endl;
}

// >> 运算符重载和测试
std::istream& operator>>(std::istream& is, Complex& c1) {
    is >> c1.real_ >> c1.image_;
    return is;
}

void test3() {
    Complex c1;
    std::cout << "input real and image" << "\n";
    std::cin >> c1;
    std::cout << c1 << std::endl;
}

int main() {
    // test();
    // test2();
    test3();
    return 0;
}
