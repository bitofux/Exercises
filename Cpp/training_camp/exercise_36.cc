/*编写一个C++程序，要求从标准输入读取两个整数，计算它们的和，并将结果输出到标准输出*/

#include <iostream>

int main() {
    int num1, num2;
    std::cout << "输入两个整数: \n";
    std::cin >> num1 >> num2;

    std::cout << num1 << " + " << num2 << " = " << num1 + num2 << "\n";

    return 0;
}
