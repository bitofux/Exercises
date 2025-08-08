// 编写一个C++程序，定义一个类BankAccount，该类包含静态
// 和非静态成员函数。静态成员函数尝试访问类的非静态成员
// 变量，并捕获编译时错误，然后通过修改代码来展示如何
// 在静态成员函数中通过对象实例访问非静态成员
#include <iostream>

class BankAccount {
public:
    BankAccount(const double money)
        : money_{money} {
        std::cout << "BankAccount(const double)\n";
    }
    // 非静态成员函数
    void show() const { std::cout << "money: " << money_ << '\n'; }
    // 静态成员函数
    //  static void print() {
    //      std::cout << money_ << '\n';//error
    //  }
    //  静态成员函数
    static void print(const BankAccount& other) {
        std::cout << other.money_ << '\n';  // error
    }

private:
    double money_;
};

int main() {
    BankAccount ba{20000.0};

    // 调用非静态成员函数
    ba.show();

    // 使用ba对象示例和类名调用静态成员函数
    BankAccount::print(ba);

    return 0;
}
