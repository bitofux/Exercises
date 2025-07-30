/*编写一个程序，声明并初始化一个二维整型数组（如矩阵），然后编写一个函数，该函数计算并返回矩阵中所有元素的和。在main函数中测试该函数*/

#include <cstddef>
#include <iostream>

namespace {
int sum_arr(int* arr, int row, int col) {
    int sum = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            sum += arr[i * col + j];
        }
    }
    return sum;
}
}  // namespace
int main() {
    int arr[3][4] = {{1, 3, 5, 7}, {2, 4, 6, 8}, {10, 20, 30, 40}};
    std::cout << sum_arr(arr[0], 3, 4) << std::endl;

    return 0;
}
