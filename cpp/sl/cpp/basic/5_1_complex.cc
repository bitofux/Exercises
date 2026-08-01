/****************************************************
 * @file    5_1_complex.cc
 * @brief   实现一个简单的复数类: 学习运算符重载
 *          使对象的运算表现的和编译器内置的类型一样
 * @author  bitofux
 * @date    2025-09-17
 ****************************************************/
#include <iostream>

class Complex {
public:
    // 单个参数的构造函数:可以实现int到Complex的隐式转换
    Complex(int real)
        : _real{real},
          _image{0} {}
    Complex(int real, int image)
        : _real{real},
          _image{image} {
        std::cout << "Complex(int,int)\n";
    }
    // + 运算符重载函数
    Complex operator+(const Complex& rhs) {
        return Complex{this->_real + rhs._real, this->_image + rhs._image};
    }
    Complex operator+(const Complex& rhs) const {
        return Complex{this->_real + rhs._real, this->_image + rhs._image};
    }
    Complex operator+(const int rhs) const { return Complex{this->_real + rhs, this->_image}; }
    Complex operator+(const int rhs) { return Complex{this->_real + rhs, this->_image}; }

    // 自增运算符重载
    //  后自增
    Complex operator++(int) { return Complex{this->_real++, this->_image++}; }
    // 前自增
    Complex& operator++() {
        this->_real++;
        this->_image++;
        return *this;
    }
    // +=
    Complex operator+=(const Complex& rhs) {
        this->_real += rhs._real;
        this->_image += rhs._image;
        return *this;
    }

    void show() const { std::cout << "real: " << _real << " image: " << _image << "\n"; }

private:
    int _real;
    int _image;
    friend Complex operator+(const int lhs, const Complex& rhs);
    friend std::ostream& operator<<(std::ostream& os, const Complex& rhs);
    friend std::istream& operator>>(std::istream& is, Complex& rhs);
};

// 全局的operator+运算符重载函数
Complex operator+(const int lhs, const Complex& rhs) {
    return Complex{lhs + rhs._real, rhs._image};
}
// 全局的operator<<运算符重载函数
std::ostream& operator<<(std::ostream& os, const Complex& rhs) {
    return (os << "real: " << rhs._real << " image: " << rhs._image);
}
// 全局的operator>>运算符重载函数
std::istream& operator>>(std::istream& is, Complex& rhs) { return (is >> rhs._real >> rhs._image); }
int main() {
    using cpx = Complex;
    const cpx com1{10, 20};
    cpx com2{10, 20};
    // 两个Complex类型的对象相加
    cpx com3{com1 + com2};
    com3.show();
    // 左边是Complex类型 右边是整数类型
    // 由于左边操作数是类类型 因此是它调用成员函数
    // 可以在类内专门实现一个参数为int的运算符+的重载
    // 函数,也可以写一个单int类型的构造函数,先将int
    // 转换为Complex类型,这时候就是两个Complex类型相加
    Complex com4{com1 + 10};
    com4.show();
    // 此时左边是int,int是一个类型,我们无法在int内部定义
    // 一个成员函数,当在Complex类中找不到此对应的运算符
    // 重载的成员函数时，就去全局去找,在全局中定义一个
    Complex com5{5 + com2};
    com5.show();

    // 自增运算符
    // 注意前自增和后自增(后自增的运算符重载函数中多一个int参数)
    com5 = com2++;  // com2后自增
    com5.show();
    com2.show();

    com4 = ++com3;
    com4.show();
    com3.show();

    // 复合赋值运算符
    com5 += com1;
    com1.show();
    com5.show();

    // 对象信息的输出
    // 假设有一个函数模板,用于输出传入的参数
    // 那么对于自定义的类型,就需要有这个自定义类型的
    // 输出运算符重载函数 也就是<<
    std::cout << com5 << "\n";

    // 对象信息的输入
    std::cout << "输入运算符重载\n";
    std::cin >> com5 >> com3;
    std::cout << com5 << "\n";
    std::cout << com3 << "\n";

    return 0;
}
