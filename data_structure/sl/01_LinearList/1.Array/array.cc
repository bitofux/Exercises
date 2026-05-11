/*
 * PROJECT : EXERCISES
 * FILE    : array.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-05-11
 * BRIEF   : 顺序表 -> 源文件
 */

#include "array.h"
#include <cstddef>
#include <cstdio>
#include <cstring>

// 构造函数
Array::Array(size_t capacity)
    : capacity_{capacity},
      size_(0),
      ptr_(new int[size_]{}) {
    std::cout << "Array(size_t,size_t)\n";
}

// 析构函数
Array::~Array() {
    delete[] ptr_;
    ptr_ = nullptr;
    std::cout << "~Array()\n";
}

// 扩容函数
void Array::expand(size_t new_capacity) {
    int* tmp = new int[new_capacity]{0};
    if (tmp == NULL) return;
    memcpy(tmp, ptr_, size_ * sizeof(int));
    delete[] ptr_;
    ptr_ = tmp;
    capacity_ = new_capacity;
}
// 末尾增加元素
void Array::push_back(int val) {
    // 判断当前顺序表是否已满，需要扩容
    if (size_ == capacity_) {
        expand(capacity_ * 2);
    }
    // size代表后一个元素的下标
    ptr_[size_] = val;
    // size增加1
    ++size_;
}

// 末尾删除元素
void Array::pop_back() { --size_; }

// 按位置增加元素
void Array::insert(int pos, int val) {
    // 判断pos是否合法
    if (pos < 0 || pos > size_) {
        return;
    } else if (pos == size_) {
        // 扩容
        if (capacity_ == size_) expand(2 * capacity_);
        push_back(val);
        return;
    }

    // 判断顺序表是否已满，需要扩容
    if (capacity_ == size_) {
        expand(capacity_ * 2);
    }

    // 计算数组pos对应真实的数组下标
    int index = pos - 1;
    // 移动数据元素
    int start = size_ - 1;
    int end = index;
    for (int i = start; i >= end; --i) {
        ptr_[i + 1] = ptr_[i];
    }

    // 插入新元素
    ptr_[index] = val;
    // 元素+1
    ++size_;
}

// 元素查询，返回数组中真实的下标
int Array::find(int val) const {
    // 若顺序表为空
    if (size_ == 0) {
        return -1;
    }
    // 若顺序表不为空
    for (int i = 0; i < size_; ++i) {
        if (ptr_[i] == val) {
            return i;
        }
    }
    return -1;
}

// 按元素删除
void Array::erase(int val) {
    // 若顺序表为空
    if (size_ == 0) return;

    // 获取该元素的下标
    int index = find(val);

    // 检查下标的合法性
    if (index < 0 || index > (size_ - 1)) return;

    // 移动数据元素
    int start = index + 1;
    int end = size_ - 1;
    for (int i = start; i <= end; ++i) {
        ptr_[i - 1] = ptr_[i];
    }

    // 元素减去一
    --size_;
}

// 输出顺序表的元素以及元素个数
void Array::show() const {
    std::cout << "element count: "<< size_ << "\ncapacity: " << capacity_ << std::endl;
    for (int i = 0; i < size_; ++i) {
        std::cout << ptr_[i] << " ";
    }
    std::cout << "\n";
}

// 返回顺序表的个数
int Array::size() const {
  return size_;
}
