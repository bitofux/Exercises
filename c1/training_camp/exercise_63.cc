// 编写一个C++函数，该函数接收一个整型数组和大小和一个整型
// 引用作为参数。函数通过引用参数返回数组中的最大值
// 并打印出该最大值
#include <iostream>

void findMax(int arr[], size_t size, int& max) {
    max = arr[0];
    for (size_t i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
}
int main() {
    int max = -1;
    int arr[5] = {-2, -34, -23, -3, 0};
    constexpr int kLen = sizeof(arr) / sizeof(arr[0]);
    findMax(arr, kLen, max);

    std::cout << "max: " << max << '\n';

    return 0;
}
