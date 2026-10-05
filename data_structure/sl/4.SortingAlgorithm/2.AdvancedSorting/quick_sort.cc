/*
 * PROJECT : EXERCISES
 * FILE    : quick_sort.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-09-22
 * BRIEF   : 快速排序 -- quick_sort
 */
#include <random>
#include <iostream>
#include <utility>

int partition(int* arr, int lower, int upper) {
    // 确定基准元素
    int pivot = arr[lower];
    // 记录基准元素的下标
    int index = lower;

    // 外层循环
    while (lower < upper) {
        // 找出大于基准元素的数据元素对应的下标
        while (lower < upper && arr[lower] <= pivot) {
            ++lower;
        }
        // 找出小于等于基准元素的数据
        while (arr[upper] > pivot) {
            --upper;
        }

        // 若lower < upper，交换它们对应的数据
        if (lower < upper) std::swap(arr[lower], arr[upper]);
    }

    // 交换upper与当前基准元素所在的下标对应的数据
    std::swap(arr[upper], arr[index]);

    return upper;
}

int partition_one(int* arr, int start, int end) {
    int pivot = arr[start];
    while (start < end) {
        while (arr[end] > pivot) {
            --end;
        }

        if (start < end) {
            arr[start] = arr[end];
            start++;
        }

        while (start < end && arr[start] < pivot) {
            ++start;
        }

        if (start < end) {
            arr[end] = arr[start];
            --end;
        }
    }

    arr[end] = pivot;

    return end;
}

void quick_sort(int* arr, int begin, int end) {
    if (begin >= end) {
        return;
    }

    int pos = partition_one(arr, begin, end);
    quick_sort(arr, begin, pos - 1);
    quick_sort(arr, pos + 1, end);
}

int main() {
    int arr[10] = {0};
    std::random_device rd;
    std::minstd_rand msr{rd()};
    std::uniform_int_distribution<> distrib{1, 100};

    for (auto& val : arr) {
        val = distrib(msr);
    }

    for (auto val : arr) {
        std::cout << val << " ";
    }
    std::cout << "\n";

    for (auto val : arr) {
        std::cout << val << " ";
    }
    std::cout << "\n";
    quick_sort(arr, 0, 9);
    for (auto val : arr) {
        std::cout << val << " ";
    }
    std::cout << "\n";
}
