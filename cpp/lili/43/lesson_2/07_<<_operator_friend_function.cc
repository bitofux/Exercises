// 输出流运算符重载 <<
// 便于打印自定义类型对象的数据
#include <cstdlib>
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
    friend std::ostream& operator<<(std::ostream& os, const Complex& rhs);
    void print() const { std::cout << "(" << real_ << "," << image_ << ")\n"; }

private:
    double real_;
    double image_;
};

// 由于<<是两元运算符，且不能改变操作数的顺序
// 因此使用成员函数重载不可以，使用全局函数+友元吧
std::ostream& operator<<(
    std::ostream& os,
    const Complex& rhs) {  // 不对os使用const的原因是<<是输出流运算符，需要对os进行写入
    // 实部和虚部同时为0
    if (0 == rhs.real_ && 0 == rhs.image_) {
        os << 0;
    } else if (0 == rhs.real_) {    // 实部为0
        if (rhs.image_ > 0) {       // 虚部大于0
            if (rhs.image_ != 1) {  // 虚部不等于1
                os << rhs.image_ << "i";
            } else {  // 虚部等于1
                os << "i";
            }
        } else {                     // 虚部小于0
            if (rhs.image_ != -1) {  // 虚部不等于-1
                os << rhs.image_ << "i";
            } else {  // 虚部等于-1
                os << "-i";
            }
        }
    } else if (0 == rhs.image_) {  // 虚部为0
        os << rhs.real_;
    } else {  // 虚部和实部都不为0
        if (rhs.image_ > 0) {
            if (rhs.image_ != 1) {
                os << rhs.real_ << " + " << rhs.image_ << "i";
            } else {
                os << rhs.real_ << " + " << "i";
            }
        } else {
            if (rhs.image_ != -1) {
                // 使用绝对值是为了想要负号显示的更好
                os << rhs.real_ << " - " << std::abs(rhs.image_) << "i";
            } else {
                os << rhs.real_ << " - i";
            }
        }
    }

    return os;
}
void test() {
    Complex c1{1, -1};
    std::cout << "c1 = ";
    // 这样的方式太麻烦
    c1.print();
    // 我想要的是这样的
    // 就需要重载<<运算符
    std::cout << "c1 = " << c1 << '\n';
}
int main() {
    test();

    return 0;
}
