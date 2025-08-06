// 编写一个C++程序，其中包含一个函数divide，该函数接收两个
// 整数作为参数，并返回它们的除法结果。如果除数为0，则该
// 函数应抛出一个std::runtime_error异常。在main函数中
// 调用divide函数并捕获可能抛出的异常，打印出异常信息
#include <iostream>
#include <stdexcept>

int divide(int dividend, int divider) {
    if (divider == 0) {
        throw std::runtime_error{"divider is zero!"};
    }

    return dividend / divider;
}
int main() {
    int dividend = 10, divider = 0;
    try {
        divide(dividend, divider);
    } catch (const std::runtime_error& ref) {
        std::cout << ref.what() << std::endl;
    }

    return 0;
}
