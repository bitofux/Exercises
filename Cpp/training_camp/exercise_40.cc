/*数组元素查找
编写一个程序，声明一个整型数组，并初始化为一些随机整数。编写一个函数，该函数接受数组、数组大小和要查找的元素作为参数，如果找到该元素，则返回其在数组中的索引；如果未找到，则返回-1。在main函数中测试该函数*/
#include <cstddef>
#include <cstdint>
#include <random>
#include <iostream>

namespace {
int find_val(int16_t* arr, size_t length, int16_t val) {
    for (size_t i = 0; i < length; i++) {
        if (*(arr + i) == val) {
            return i;
        }
    }
    return -1;
}
}  // namespace
int main() {
    // 随机设备
    std::random_device rd;
    // 使用rd()生成随机数种子
    std::mt19937 gen{rd()};
    // 设置区间为[1-10]
    std::uniform_int_distribution<int16_t> dis(1, 10);

    // 定义一个数组
    int16_t arr[10];
    // 使用随机数初始化数组
    for (auto& p : arr) {
        p = dis(gen);
    }
    std::cout << find_val(arr, 10, 5) << std::endl;

    return 0;
}
