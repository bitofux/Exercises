// 1.声明一个constexpr整型变量并初始化
// 2.使用该constexpr变量作为数组的大小
#include <iostream>

int main() {
    constexpr int size = 10;

    int arr[size] = {0};

    for (const auto& ref : arr) {
        std::cout << ref << ' ';
    }
    std::cout << '\n';

    return 0;
}
