/*
 * PROJECT : EXERCISES
 * FILE    : insertion_sort.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-09-12
 * BRIEF   : 插入排序
 */
#include <iostream>
#include <random>

void insertion_sort_one(int arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        int val = arr[i + 1];
        int j = i;
        for (; j >= 0; --j) {
            if (arr[j] <= val) {
                break;
            }
        }
        // 判断j + 1与i是否相等，若相等则不需要移动和插入数据
        if (j + 1 > i) {
            continue;
        }

        // 从后一个元素开始移动数据
        for (int k = i; k >= j + 1; --k) {
            arr[k + 1] = arr[k];
        }

        // 插入数据
        arr[j + 1] = val;
    }
}
void insertion_sort_two(int arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        int val = arr[i + 1];
        int j = i;
        for (; j >= 0; --j) {
            if (arr[j] <= val) {
                break;
            }
            // 移动数据
            arr[j + 1] = arr[j];
        }

        // 插入数据
        arr[j + 1] = val;
    }
}

void insertion_sort_three(int arr[], int size) {
    for (int i = 1; i < size; ++i) {
        int val = arr[i];
        int j = i - 1;
        for (; j >= 0; --j) {
            if (arr[j] <= val) {
                break;
            }
            // 移动数据
            arr[j + 1] = arr[j];
        }

        // 插入数据
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

    insertion_sort_three(arr, sizeof(arr) / sizeof(arr[0]));

    for (int ele : arr) {
        std::cout << ele << " ";
    }
    std::cout << "\n";
}
