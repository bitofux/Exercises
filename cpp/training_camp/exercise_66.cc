// 编写一个程序，该程序包含三个函数：A、B和C。函数A调用函数B，函数B调用函数C。
// 函数C负责执行某个可能抛出异常的操作（如题目1或题目2中的除法运算）。如果发生异常，异常应能被A函数中的try-catch块捕获并处理。
#include <exception>
#include <iostream>

class MyException : public std::exception {
public:
    MyException(const std::string msg)
        : msg_{msg} {}
    const char* what() const noexcept override { return msg_.c_str(); }

private:
    std::string msg_;
};
int C(int dividend, int divider) {
    if (divider == 0) {
        throw MyException{"divider is zero"};
    }

    return dividend / divider;
}

void B() {
    int dividend = 10, divider = 0;
    // 不捕获异常,不处理异常
    C(dividend, divider);
}
int main() {
    // 捕获异常,处理异常
    try {
        B();
    } catch (const MyException& ref) {
        std::cout << ref.what() << std::endl;
    }

    std::cout << "捕获并处理异常完成!\n";
    return 0;
}
