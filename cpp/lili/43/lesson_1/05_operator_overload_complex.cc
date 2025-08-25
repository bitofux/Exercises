// 认识运算符重载
#include <iostream>

class Complex {
public:
    Complex(double real = 0.0, double dimage = 0.0)
        : real_{real},
          dimage_{dimage} {
        std::cout << "Complex(double,double)\n";
    }
    Complex(const Complex& other) { std::cout << "Complex(const Complex&)\n"; }
    void print() const { std::cout << real_ << " + " << dimage_ << "i\n"; }
    ~Complex() { std::cout << "~Complex()\n"; }

public:
    Complex operator+(const Complex& other) {
        return Complex{this->real_ + other.real_, this->dimage_ + other.dimage_};
    }

private:
    double real_;
    double dimage_;
};

int main() {
    Complex c1{1, 2}, c2{4, 3};
    std::cout << "c1 = ";
    c1.print();
    std::cout << "c2 = ";
    c2.print();

    // 使用+运算符来计算两个Complex类型对象
    // Complex c3 = c1 + c2;//error 自定义类型Complex不支持+运算符，可将+运算符进行重载以支持Complex
    Complex c3 = c1 + c2;
    c3.print();
    return 0;
}
