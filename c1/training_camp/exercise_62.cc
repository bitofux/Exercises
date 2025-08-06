// 1.编写一个constexpr函数，该函数接收两个整型参数并返回
// 它们的和
// 2.在main函数中调用该constexpr函数，并使用其返回值作为
// 另一个数组的大小
#include <iostream>

constexpr int add(const int a, const int b) { return a + b; }
int main() {
    const int arr[add(2, 3)] = {1, 2, 3, 4, 5};

    for (const auto& ref : arr) {
        std::cout << ref << ' ';
    }
    std::cout << '\n';

    return 0;
}
