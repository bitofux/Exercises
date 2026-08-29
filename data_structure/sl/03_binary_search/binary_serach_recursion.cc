/*
 * PROJECT : EXERCISES
 * FILE    : binary_serach_recursion.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-08-26
 * BRIEF   : 二分搜索 -- 递归实现
 */

#include <iostream>

// 递归实现：有些多余的设计
static int binary_search_recursion(int arr[], int first, int last, int val) {
    if (first > last) {
        return -1;
    }
    int middle = (first + last) / 2;

    if (arr[middle] == val) {
        return middle;
    }

    int result = -1;
    if (val < arr[middle]) {
        last = middle - 1;
        result = binary_search_recursion(arr, first, last, val);
        if (result == -1) {
            return -1;
        }
    }

    if (val > arr[middle]) {
        first = middle + 1;
        result = binary_search_recursion(arr, first, last, val);
        if (result == -1) {
            return -1;
        }
    }

    return result;
}

/*
 * @brief 对一个有序序列执行二分搜索算法
 *
 * @param[in] arr 存储有序序列的数组
 * @param[in] first 搜索区间的起始下标
 * @param[in] last 搜索区间的末尾下标
 * @param[in] var 要搜索的数据元素
 *
 * @retval -1 搜索不到返回-1
 * @retval 非-1 返回在数组中的下标
 */
int binary_search_recursion(const int arr[], int first, int last, int var) {
    // 区间范围异常
    if (first > last) {
        return -1;
    }

    int middle = (first + last) / 2;
    // 区间数据规模为1
    if (arr[middle] == var) {
        return middle;
    } else if (arr[middle] > var) {
        return binary_search_recursion(arr, first, middle - 1, var);
    } else {
        return binary_search_recursion(arr, middle + 1, last, var);
    }
}

int main() {
    const int arr[] = {12, 25, 30, 32, 42, 54, 67, 73, 89, 99, 102};
    std::cout << binary_search_recursion(arr, 0, 10, 12) << std::endl;
    std::cout << binary_search_recursion(arr, 0, 10, 25) << std::endl;
    std::cout << binary_search_recursion(arr, 0, 10, 30) << std::endl;
    std::cout << binary_search_recursion(arr, 0, 10, 32) << std::endl;
    std::cout << binary_search_recursion(arr, 0, 10, 102) << std::endl;
    std::cout << binary_search_recursion(arr, 0, 10, 42) << std::endl;
    std::cout << binary_search_recursion(arr, 0, 10, 11) << std::endl;

    return 0;
}
