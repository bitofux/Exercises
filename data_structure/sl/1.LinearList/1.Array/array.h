/*
 * PROJECT : EXERCISES
 * FILE    : array.h
 * AUTHOR  : bitofux
 * DATE    : 2026-05-11
 * BRIEF   : 顺序表 -- 头文件
 */

#ifndef EXERCISES_ARRAY_H_
#define EXERCISES_ARRAY_H_

#include <cstddef>
#include <iostream>

class Array {
public:
    // 构造与析构函数
    Array(size_t capacity);
    ~Array();

    // 末尾增加元素
    void push_back(int val);
    // 末尾删除元素
    void pop_back();
    // 按位置增加元素
    void insert(int pos, int val);
    // 按元素值删除
    void erase(int val);
    // 查找元素并返回其的下标
    int find(int val) const;
    // 输出当前顺序表的元素个数和元素值
    void show() const;
    // 返回当前顺序表的个数
    int size() const;

    // 获取动态数组的首元素指针
    int* c_str() const;

private:
    void expand(size_t new_capacity);

    size_t capacity_;  // 顺序表的容量
    size_t size_;      // 当前顺序表的元素个数
    int* ptr_;         // 指向堆内存的指针
};

#endif  // EXERCISES_ARRAY_H_
