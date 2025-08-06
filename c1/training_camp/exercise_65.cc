// 定义一个自定义异常类DivideByZeroException，该类继承自
// std::exception，并实现what()方法以返回“Cannot divide by zero”作为异常描述。
// 然后，修改题目1中的divide函数，在除数为0时抛出DivideByZeroException异常。最后，在main函数中捕获并处理这个自定义异常
#include <iostream>
#include <exception>

class DivideByException : public std::exception {
public:
    DivideByException(const std::string msg)
        : msg_{msg} {}
    virtual const char* what() const noexcept override { return msg_.c_str(); }

private:
    std::string msg_;
};

int divide(int dividend, int divider) {
    if (divider == 0) {
        throw DivideByException{"DivideByZeroException"};
    }

    return dividend / divider;
}
int main() {
    int dividend = 10, divider = 0;
    try {
        divide(dividend, divider);
    } catch (const DivideByException& ref) {
        std::cout << ref.what() << std::endl;
    }

    return 0;
}
