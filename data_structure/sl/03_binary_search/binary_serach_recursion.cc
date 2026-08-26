/*
 * PROJECT : EXERCISES
 * FILE    : binary_serach_recursion.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-08-26
 * BRIEF   : 二分搜索 -- 递归实现
 */

#include <cstddef>
#include <iostream>
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
int main() {
    int arr[] = {12, 25, 30, 32, 42, 54, 67, 73, 89, 99, 102};
    std::cout << binary_search_recursion(arr, 0, 10, 12) << std::endl;
    std::cout << binary_search_recursion(arr, 0, 10, 25) << std::endl;
    std::cout << binary_search_recursion(arr, 0, 10, 30) << std::endl;
    std::cout << binary_search_recursion(arr, 0, 10, 32) << std::endl;
    std::cout << binary_search_recursion(arr, 0, 10, 102) << std::endl;
    std::cout << binary_search_recursion(arr, 0, 10, 42) << std::endl;
    std::cout << binary_search_recursion(arr, 0, 10, 11) << std::endl;

    return 0;
}
