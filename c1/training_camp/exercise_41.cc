/*编写一个程序，声明一个整型数组，并初始化为一些未排序的整数。使用冒泡排序算法对数组进行排序，并打印排序后的数组。*/
#include <cstddef>
#include <iostream>
#include <random>
int main() {
    // 随机数
    std::random_device rd;
    std::mt19937 gen{rd()};
    std::uniform_int_distribution<int> uid(20, 40);

    // 定义一个数组
    int arr[10];
    for (auto& ref : arr) {
        ref = uid(gen);
    }
    // 数组长度
    size_t length = sizeof(arr) / sizeof(int);

    // 进行排序
    for (size_t i = 0; i < length - 1; i++) {  // 比较几轮
        bool is_swap = false;
        for (size_t j = 0; j < length - 1 - i; j++) {  // 每轮比较多少次
            // 升序
            if (arr[j] > arr[j + 1]) {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
                is_swap = true;
            }
        }
        if (!is_swap) {
            break;
        }
    }

    // 将排序后的数组进行输出
    for (auto& ref : arr) {
        std::cout << ref << ' ';
    }
    std::cout << std::endl;

    return 0;
}
