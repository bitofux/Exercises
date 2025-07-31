// 实现一个计算函数，该函数接受一个整数数组和一个回调函数作为参数
// 回调函数用于对每个数组元素进行操作(比如计算每个元素的平方)
// 并将操作后的结果存储回原数组
#include <iostream>
void operaArray(int* arr, size_t size) {
    for (size_t i = 0; i < size; i++) {
        arr[i] *= arr[i];
    }
}
typedef void (*p_func)(int*, size_t);

void calculate(int arr[], size_t size, p_func func) { func(arr, size); }
int main() {
    int arr[5] = {2, 4, 6, 8, 10};
    size_t len = sizeof(arr) / sizeof(arr[0]);

    calculate(arr, len, operaArray);

    for (auto& ref : arr) {
        std::cout << ref << ' ';
    }

    std::cout << '\n';

    return 0;
}
