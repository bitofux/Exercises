/*
 * PROJECT : EXERCISES
 * FILE    : exception.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-03-17
 * BRIEF   : 异常
 */
#include <iostream>
#include <locale>
#include <string>

template <typename T>
class MyException {
public:
    MyException(T value, std::string str)
        : value_{value},
          str_{str} {
        std::cout << "MyException(T,std::string)\n";
    }
    ~MyException() { std::cout << "~MyException()\n"; }
    void what() const { std::cout << value_ << " " << str_ << "\n"; }

private:
    T value_;
    std::string str_;
};
int divide(int a, int b) {
    if (b == 0) {
        throw MyException<int>{b, "is zero"};
    } else {
        return a / b;
    }
}

int main() {
    int a = 10, b = 0;
    try {
        int result = divide(a, b);
        std::cout << "result: " << result << "\n";
    } catch (MyException<int>& e) {
        e.what();
    } catch (...) {
    }
}
