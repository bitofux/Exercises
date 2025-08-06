// 1.编写一个enum class,名为Color,包含red、GREEN、BLUE三个枚举值
// 2.编写代码尝试直接访问RED(不通过Color::前缀),并理解为什么编译器会报错
// 3.编写代码将Color::RED显示转换为int类型并打印结果

#include <iostream>

enum class Color { RED, GREEN, BLUE };

int main() {
    // 不通过作用域解析运算符访问RED
    //  std::cout << RED << std::endl;//error 未声明的RED标识符
    std::cout << static_cast<int>(Color::RED) << '\n';

    return 0;
}
