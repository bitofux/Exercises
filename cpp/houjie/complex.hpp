#ifndef __COMPLEX__
#define __COMPLEX__

class Complex {
public:
    Complex(const double re, const double im);
    // 成员函数
    // +=运算符重载
    Complex& operator+=(const Complex&);
    // -=运算符重载
    Complex& operator-=(const Complex&);
    // *=运算符重载
    Complex& operator*=(const Complex&);
    // /=运算符重载
    Complex& operator/=(const Complex&);
    double real() const;
    double image() const;

private:
    double _re, _im;
};
#endif
