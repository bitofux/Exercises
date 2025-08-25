// 前置++运算符重载,这种对于自身对象会发生改变的
// 以成员函数形式进行重载
#include <iostream>

class Complex {
public:
    Complex(double real = 0.0, double image = 0.0)
        : real_{real},
          image_{image} {
        std::cout << "Complex(double,double)\n";
    }
    // 拷贝构造函数
    Complex(const Complex& other)
        : real_{other.real_},
          image_{other.image_} {
        std::cout << "Complex(const Complex &)\n";
    }
    // 重载前置++运算符,前置++运算符的结果是自身 左值
    // 返回值可是左值引用
    Complex& operator++() {
        ++this->real_;
        ++this->image_;
        return *this;
    }
    void print() const { std::cout << "(" << real_ << "," << image_ << ")\n"; }

private:
    double real_;
    double image_;
};

void test() {
    Complex c1{2, 3};
    std::cout << "c1 = ";
    c1.print();

    // 利用前置++运算符,给实部和虚部同时增加1
    ++c1;
    std::cout << "(++c1) = ";
    c1.print();
}
int main() {
    test();

    return 0;
}
