// 编写一个程序，定义一个函数printType,该函数接收一个整型参数，并判断该参数是左值还是右值。
#include <iostream>

void printType(int&) { std::cout << "左值\n"; }
void printType(int&&) { std::cout << "右值\n"; }
template <typename T>
void accessType(T&& value) {
    //需要std::forward,否则当传入参数为rvalue时
    //进入函数内value就是一个实在的左值
    // printType(value);
    printType(std::forward<T>(value));
}
int main() {
    // var is lvalue
    int var = 10;
    accessType(var);

    // 使用移动语义std::move(var) 这个表达式是一个xvalue
    accessType(std::move(var));

    // 纯右值
    accessType(42);

    return 0;
}
