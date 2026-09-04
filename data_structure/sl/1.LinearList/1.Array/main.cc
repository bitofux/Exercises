/*
 * PROJECT : EXERCISES
 * FILE    : main.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-05-11
 * BRIEF   : 测试文件
 */

#include "array.h"
#include <iostream>

int main() {
    std::cout << "Array size: " << sizeof(Array) << "\n";

    // 定义一个顺序表
    Array arr{10};

    // 输出顺序表
    arr.show();

    // 尾部插入十个元素
    for (int i = 0; i < 5; ++i) {
        arr.push_back(i * 3);
    }

    // 输出顺序表
    arr.show();

    // 在第1个位置插入元素
    arr.insert(1, 20);
    arr.show();

    // 在第6个位置插入元素
    arr.insert(6, 30);
    arr.show();

    // 在末尾再添加3个元素
    for (int i = 0; i < 3;++i) {
      arr.push_back(i * 5);
    }
    arr.show();

    // 在第10个位置上插入元素
    arr.insert(10, 21);
    arr.show();

    // 删除元素5
    arr.erase(5);
    arr.show();

    // 删除不存在的元素
    arr.erase(8);
    arr.show();

    // 末尾删除元素
    arr.pop_back();
    arr.show();
    arr.pop_back();
    arr.pop_back();
    arr.show();
    return 0;
}
