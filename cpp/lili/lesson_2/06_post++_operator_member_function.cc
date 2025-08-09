// 后置++运算符重载,这种对于自身对象会发生改变的
// 以成员函数形式进行重载

/*前置++比后置++效率高吗？
 *前置++是没有拷贝的，而后置++是有拷贝的
 *特别是在这个上下文中，后置++执行了两次拷贝操作
 *后置++这个表达式的值类别是右值
 *前置++这个表达式的值类别是左值*/
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
    // 返回值类型可是左值引用
    Complex& operator++() {
        ++this->real_;
        ++this->image_;
        return *this;
    }
    // 重置后置++运算符，后置++运算符的结果是增加之前
    // 操作数的值，是一个右值，返回值类型是本类型即可
    // 这样的函数是重载不了的，因此C++标准中可以在此加
    // 一个类型int，仅仅是为了标识和重载使用
    Complex operator++(int) {
        Complex tmp{*this};
        (*this).real_++;
        (*this).image_++;
        return tmp;
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

    // 利用后置++运算符,给实部和虚部同时增加1
    // 但是c1++这个表达式的结果还是c1未增加
    // 之前的值
    Complex&& ref = c1++;
    std::cout << "(c1++) = ";
    ref.print();
}
int main() {
    test();

    return 0;
}
