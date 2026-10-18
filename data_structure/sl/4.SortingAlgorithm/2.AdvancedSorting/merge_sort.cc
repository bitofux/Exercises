/*
 * PROJECT : EXERCISES
 * FILE    : merge_sort.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-10-10
 * BRIEF   : 归并排序 -- merge_sort
 */

#include <iostream>
#include <random>

void merge_data(int* arr, int start, int end, int mid) {
    // 申请所需的额外内存空间用于保存有序数据
    int* p = new int[end - start + 1]{0};
    // 表示p指向的数组的下标
    int idx = 0;
    // 指向左叶子节点表示的子序列起始位置
    int i = start;
    // 指向右叶子节点表示的子序列起始位置
    int j = mid + 1;

    // 循环比较两个子序列的数据元素
    while (i <= mid && j <= end) {
        // 若左叶子节点当前的数据元素比右叶子节点当前的数据元素小于或者等于
        if (arr[i] <= arr[j]) {
            p[idx++] = arr[i++];
        } else {
            p[idx++] = arr[j++];
        }
    }

    // 若左边叶子节点表示的子序列没有遍历完毕
    while (i <= mid) {
        p[idx++] = arr[i++];
    }

    // 若右边叶子节点表示的子序列没有遍历完毕
    while (j <= end) {
        p[idx++] = arr[j++];
    }

    // 将额外内存空间的数据拷贝到原数组
    for (i = start, j = 0; i <= end; ++i, ++j) {
        arr[i] = p[j];
    }

    // 释放内存
    delete[] p;
}
void merge_sort(int* arr, int start, int end) {
    if (start >= end) {
        return;
    }
    int mid = (start + end) / 2;
    merge_sort(arr, start, mid);
    merge_sort(arr, mid + 1, end);

    // 数据归并
    merge_data(arr, start, end, mid);
}

int main() {
    std::random_device rd;
    std::minstd_rand msr{rd()};
    std::uniform_int_distribution<> distrib{1, 100};

    int arr[10] = {0};
    for (auto& val : arr) {
        val = distrib(msr);
    }

    for (auto val : arr) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    merge_sort(arr, 0, 9);

    for (auto val : arr) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}
