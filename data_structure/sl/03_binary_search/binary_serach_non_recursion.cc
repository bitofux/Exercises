/*
 * PROJECT : EXERCISES
 * FILE    : binary_serach_non_recursion.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-08-22
 * BRIEF   : 非递归实现二分搜索
 */
#include <iostream>

/*
 * @brief 非递归实现二分搜索
 *
 * @param[in] arr 要查找的有序序列
 * @param[in] size 有序序列的长度
 * @param[in] val 查找的目标值
 *
 * @retval index 目标值在有序序列的下标
 * @retval -1 未找到目标值
 *
 * @note arr：必须是一个有序序列
 */
int binary_search(int arr[], size_t size, int val) {
    int first = 0;
    int last = size - 1;

    while (first <= last) {
        int mid = (first + last) / 2;

        if (arr[mid] == val) {
            return mid;
        }

        if (val < arr[mid]) {
            last = mid - 1;
        } else {
            first = mid + 1;
        }
    }

    return -1;
}

int main() {
    int arr[] = {12, 25, 30, 32, 42, 54, 67, 73, 89, 99, 102};

    size_t size = sizeof(arr) / sizeof(arr[0]);

    std::cout << binary_search(arr, size, 12) << std::endl;
    std::cout << binary_search(arr, size, 102) << std::endl;
    std::cout << binary_search(arr, size, 42) << std::endl;
    std::cout << binary_search(arr, size, 106) << std::endl;
    std::cout << binary_search(arr, size, 11) << std::endl;
}
