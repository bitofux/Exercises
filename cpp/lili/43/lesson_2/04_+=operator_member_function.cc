// 复合运算符+=重载,这种对于自身对象会发生改变的
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
    // 重载+=运算符 +=运算符的结果还是自己本身 左值
    // 因此类型可以是左值引用
    Complex& operator+=(const Complex& other) {
        this->real_ += other.real_;
        this->image_ += other.image_;
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

    Complex c2{3, 4};
    std::cout << "c2 = ";
    c2.print();
   
    //error，对于Complex类型识别不了运算符+=
    //需要重载+=运算符
    Complex c3 {c2+=c1};
    c3.print();
}
int main() {
    test();

    return 0;
}
