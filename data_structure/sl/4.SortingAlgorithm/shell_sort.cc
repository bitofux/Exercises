/*
 * PROJECT : EXERCISES
 * FILE    : shell_sort.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-09-15
 * BRIEF   : 希尔排序 -- shell_sort
 */
#include <iostream>
#include <random>

void insertion_sort(int arr[], int size) {
    for (int i = 1; i < size; ++i) {
        int val = arr[i];
        int j = i - 1;
        for (; j >= 0; --j) {
            if (arr[j] <= val) {
                break;
            }
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = val;
    }
}

void shell_sort(int arr[], int size) {
    int gap = size / 2;
    while (gap != 0) {
        std::cout << "gap: " << gap << "\n";
        for (int i = 0; i < gap; ++i) {
            int index = 0;
            int count = 0;
            // 计算该分组中的数据个数
            while (true) {
                index = count * gap + i;
                if (index <= size - 1) {
                    ++count;
                } else
                    break;
            }

            // 申请临时堆数组
            int* ptr = new int[count]{0};
            // 将该分组的数据按照索引拷贝到堆数组
            for (int j = 0; j < count; ++j) {
                // 计算该分组数据中有效索引
                index = j * gap + i;
                // 拷贝数据
                ptr[j] = arr[index];
            }

            std::cout << "before insertion sort: ";
            for (int j = 0; j < count; ++j) {
                std::cout << ptr[j] << " ";
            }
            std::cout << "\n";

            // 在堆数组中执行插入排序
            insertion_sort(ptr, count);

            std::cout << "after insertion sort: ";
            for (int j = 0; j < count; ++j) {
                std::cout << ptr[j] << " ";
            }
            std::cout << "\n";
            std::cout << "\n";

            // 排序之后再将堆数组中数据按照顺序拷贝到该分组中对应的索引上
            for (int j = 0; j < count; ++j) {
                index = j * gap + i;
                // 拷贝数据
                arr[index] = ptr[j];
            }

            // 释放堆数组
            delete[] ptr;
        }
        std::cout << "-------------------------------------------" << "\n";
        // 更新gap的值
        gap = gap / 2;
    }
}

void shell_sort_one(int arr[], int size) {
    int gap = size / 2;
    while (gap != 0) {
        for (int i = gap; i < size; ++i) {
            int val = arr[i];
            int j = i - gap;
            for (; j >= 0; j -= gap) {
                if (arr[j] <= val) {
                    break;
                }
                arr[j + gap] = arr[j];
            }
            arr[j + gap] = val;
        }
        gap /= 2;
    }
}

int main() {
    // #if 0
    std::random_device rd;
    std::minstd_rand msr{rd()};
    std::uniform_int_distribution<> distrib{1, 100};

    int arr[15] = {0};
    for (auto& var : arr) {
        var = distrib(msr);
    }

    for (int var : arr) {
        std::cout << var << " ";
    }
    std::cout << "\n";
    // #endif
    // int arr[15] = {58, 81, 95, 64, 21, 25, 82, 8, 15, 26, 75, 8, 7, 88, 85};
    shell_sort_one(arr, sizeof(arr) / sizeof(arr[0]));

    for (int var : arr) {
        std::cout << var << " ";
    }
    std::cout << "\n";
}
