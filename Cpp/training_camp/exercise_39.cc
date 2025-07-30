/*数组声明与初始化
编写一个程序，声明一个整型数组，并初始化为{1, 3, 5, 7, 9}，然后遍历并打印数组中的每个元素*/

#include <iostream>

int main() {
    int arr[] = {1, 3, 5, 7, 9};
    for (const auto& p : arr) {
        std::cout << p << ' ';
    }
    std::cout << std::endl;
    return 0;
}
