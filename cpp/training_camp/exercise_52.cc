// 编写一个C语言程序，定义一个指针函数int* findMax(int arr[],size_t
// size),该函数遍历一个整数数组，返回指向数组中最大值的指针
// 在主函数定义一个整数数组，调用findMax函数，并通过返回的指针打印数组中的最大值

#include <cstdlib>
#include <iostream>

int* findMax(int arr[], size_t size) {
    int* max = static_cast<int*>(malloc(sizeof(*max)));
    if (max == nullptr) {
        std::cerr << "内存分配失败\n";
        return nullptr;
    }
    *max = arr[0];
    for (size_t i = 1; i < size; i++) {
        if (arr[i] > *max) {
            *max = arr[i];
        }
    }

    return max;
}
int main() {
    int arr[10] = {-2, 32, -3, 44, 45, 7, 23, 43, 78, 12};
    size_t size = sizeof(arr) / sizeof(arr[0]);

    std::cout << *findMax(arr, size) << '\n';

    return 0;
}
