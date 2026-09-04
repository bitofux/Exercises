/*
 * PROJECT : EXERCISES
 * FILE    : bubble_sort.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-09-04
 * BRIEF   : 冒泡排序 -- bubble sort
 */
#include <cstddef>
#include <random>
#include <iostream>

static void bubble_sort(int arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j + 1] = tmp;
            }
        }
    }
}
int main() {
    std::random_device rd;
    std::minstd_rand msr{rd()};
    std::uniform_int_distribution<> distrib{1, 100};

    int arr[10] = {0};
    for (int& var : arr) {
        var = distrib(msr);
    }

    for (int var : arr) {
        std::cout << var << " ";
    }
    std::cout << "\n";

    bubble_sort(arr, sizeof(arr) / sizeof(int));

    for (int var : arr) {
        std::cout << var << " ";
    }

    std::cout << "\n";
    return 0;
}
