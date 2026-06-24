/*
 * PROJECT : EXERCISES
 * FILE    : element_reverse_order.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-06-15
 * BRIEF   : 一些算法
 */
#include "array.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iterator>

// 元素逆序
void element_reverse(const Array& arr) {
    // 获取首个元素的地址
    auto* first_ptr = arr.c_str();

    // 获取末尾元素的地址
    auto* end_ptr = arr.c_str() + arr.size() - 1;

    while ((first_ptr < end_ptr)) {
        int tmp = *first_ptr;
        *first_ptr = *end_ptr;
        *end_ptr = tmp;
        first_ptr++;
        end_ptr--;
    }
}

// 奇偶数调整
void odd_even(Array& arr) {
    // 获取首个元素的地址
    auto* first_ptr = arr.c_str();
    // 获取末尾元素的地址
    auto* end_ptr = arr.c_str() + arr.size() - 1;

    while (first_ptr < end_ptr) {
        // 判断first_ptr指向的元素值是否是偶数
        if (*first_ptr % 2 == 0) {  // 是偶数，在左边不动
            // 去判断end_ptr指向的元素是否是奇数
            if (*end_ptr % 2 != 0) {  // 是奇数
                // 交换两个元素的值
                // int tmp = *first_ptr;
                // *first_ptr = *end_ptr;
                // *end_ptr = tmp;
                ++first_ptr;
                --end_ptr;
                continue;
            } else {  // 是偶数
                // first_ptr + 1
                ++first_ptr;
                // 与end_ptr进行交换
                int tmp = *first_ptr;
                *first_ptr = *end_ptr;
                *end_ptr = tmp;
                ++first_ptr;
                // 但end_ptr此时指向的元素值还没判断，不移动指针
                continue;
            }
        } else {  // 是奇数
            // 去判断end_ptr的元素值
            if (*end_ptr % 2 == 0) {  // 若是偶数
                int tmp = *end_ptr;
                *end_ptr = *first_ptr;
                *first_ptr = tmp;
                ++first_ptr;
                --end_ptr;
                continue;
            } else {  // 是奇数
                // end_ptr + 1
                --end_ptr;
                // 与first_ptr进行交换
                int tmp = *end_ptr;
                *end_ptr = *first_ptr;
                *first_ptr = tmp;
                --end_ptr;
                // 此时first_ptr指向的元素值还没判断，不移动指针
                continue;
            }
        }
    }
}
int main() {
    Array arr{10};
    srand(time(nullptr));

    arr.push_back(31);
    arr.push_back(55);
    arr.push_back(27);
    arr.push_back(62);
    arr.push_back(3);
    arr.push_back(84);
    arr.push_back(80);
    arr.push_back(70);
    arr.push_back(48);
    arr.push_back(12);

    arr.show();
    // std::cout << "element_reverse before: " << std::endl;
    // element_reverse(arr);
    // arr.show();
    // std::cout << "element_reverse before: " << std::endl;
    odd_even(arr);
    arr.show();
}
