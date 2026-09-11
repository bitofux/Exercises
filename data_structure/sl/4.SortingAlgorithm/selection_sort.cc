/*
 * PROJECT : EXERCISES
 * FILE    : selection_sort.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-09-11
 * BRIEF   : 选择排序
 */
#include <iostream>
#include <random>

void selection_sort(int arr[], int size) {
    int min = -1;
    int idx = -1;
    for (int index = 0; index < size - 1; ++index) {
        // 选择特定位置上的数据将其赋值给min
        min = arr[index];
        // 同步更新idx
        idx = index;
        for (int j = index + 1; j < size; ++j) {
            if (min > arr[j]) {
                // 将最小值赋值给min，便于后续比较
                min = arr[j];
                // 将最小值的下标赋值给idx
                idx = j;
            }
        }

        // // 若index == idx，代表当前位置就是这一轮比较的最小值 无需交换
        if (index != idx) {
            int tmp = arr[index];
            arr[index] = arr[idx];
            arr[idx] = tmp;
        }
    }
}

int main() {
    std::random_device rd;
    std::minstd_rand msr{rd()};
    std::uniform_int_distribution<> distrib{1, 100};

    int arr[10] = {0};

    for (auto& var : arr) {
        var = distrib(msr);
    }

    for (auto& var : arr) {
        std::cout << var << " ";
    }

    std::cout << "\n";

    selection_sort(arr, sizeof(arr) / sizeof(arr[0]));
    for (auto& var : arr) {
        std::cout << var << " ";
    }

    std::cout << "\n";
}
