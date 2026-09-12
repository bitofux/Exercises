/*
 * PROJECT : EXERCISES
 * FILE    : insertion_sort.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-09-12
 * BRIEF   : 插入排序
 */
#include <iostream>
#include <random>

void insertion_sort(int arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        int val = arr[i + 1];
        int j = i;
        for (; j >= 0; --j) {
            if (arr[j] <= val) {
                break;
            }
            arr[j + 1] = arr[j];
        }

        arr[j + 1] = val;
    }
}

int main() {
    std::random_device rd;
    std::minstd_rand msr{rd()};
    std::uniform_int_distribution<> distrib{1, 100};

    int arr[10] = {0};
    for (auto& ele : arr) {
        ele = distrib(msr);
    }

    for (int ele : arr) {
        std::cout << ele << " ";
    }
    std::cout << "\n";

    insertion_sort(arr, sizeof(arr) / sizeof(arr[0]));

    for (int ele : arr) {
        std::cout << ele << " ";
    }
    std::cout << "\n";
}
