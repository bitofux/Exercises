/*
 * PROJECT : EXERCISES
 * FILE    : quick_sort.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-09-22
 * BRIEF   : 快速排序 -- quick_sort
 */
#include <random>
#include <iostream>

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
}
