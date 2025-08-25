// + 运算符重载 -- 友元函数形式
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
    friend Complex operator+(const Complex& lhs, const Complex& rhs);

private:
    double real_;
    double dimage_;
};

//+ 运算符重载 -- 全局函数形式(友元)
Complex operator+(const Complex& lhs, const Complex& rhs) {
    return Complex{lhs.real_ + rhs.real_, lhs.dimage_ + rhs.dimage_};
}

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
