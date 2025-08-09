// 输入流运算符重载 >>
// 便于从控制台和文件流或者字符串流读取数据到对象
#include <cstdlib>
#include <ios>
#include <iostream>
#include <limits>

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
    // rhs不能是常左值引用了,因为要从控制台或者文件流
    // 字符串流读取数据到rhs中 不能是只读
    friend std::istream& operator>>(std::istream& is, Complex& rhs);
    void print() const { std::cout << "(" << real_ << "," << image_ << ")\n"; }

private:
    double real_;
    double image_;
};

namespace read {
void readDouble(std::istream& is, double& data) {
    // 读取失败时不直接退出而是给出提示
    while (true) {
        if (is >> data) {
            break;
        }
        if (is.eof() || is.bad()) {
            std::cerr << "input ended or device error\n";
        }
        // 重置状态以便下次读取
        is.clear();
        is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "pls enter valid data\n";
    }
}
}  // namespace read
// 由于>>是两元运算符，且不能改变操作数的顺序
// 因此使用成员函数重载不可以，使用全局函数+友元吧
std::istream& operator>>(std::istream& is, Complex& rhs) {
    // 将读取的操作封装到一个函数中
    read::readDouble(is, rhs.real_);
    read::readDouble(is, rhs.image_);
    return is;
}
void test() {
    Complex c1{2, 3};
    std::cout << "请输入c1的数据: ";
    std::cin >> c1;
    c1.print();
}
int main() {
    test();

    return 0;
}
