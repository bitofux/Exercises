/*
 * PROJECT : EXERCISES
 * FILE    : arrry.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-07-21
 * BRIEF   : 顺序表
 */
#include <array>
#include <cstddef>
#include <cstring>
#include <iostream>
#include <new>
#include <ostream>
#include <random>

class Array {
public:
    Array(size_t cap = 20)
        : ptr_{new int[cap == 0 ? 1 : cap]{}},
          cap_{cap == 0 ? 1 : cap},
          size_{0} {}

    ~Array() { delete[] ptr_; }

    Array(const Array&) = delete;
    Array& operator=(const Array&) = delete;

    // 判断顺序表为空
    bool empty() const { return size_ == 0; }

    // 判断顺序表满了
    bool full() const { return cap_ == size_; }

    // 插入新的元素数据到尾部
    void push_back(int val) {
        // 判断当前顺序表是否满
        if (full()) {
            expand(cap_ * 2);
        }
        ptr_[size_++] = val;
    }

    // 将尾部元素删除
    void pop_back() {
        // 判断当前顺序表是否已空
        if (empty()) {
            throw "Array is empty!";
        }
        --size_;
    }

    // 获取尾部元素
    int back() const {
        // 判断顺序表是否为空
        if (empty()) {
            throw "Array is empty!";
        }
        return ptr_[size_ - 1];
    }

    // 插入新的元素到头部
    void push_front(int val) {
        // 判断当前顺序表是否满
        if (full()) {
            expand(cap_ * 2);
        }
        for (int i = size_ - 1; i >= 0; --i) {
            ptr_[i + 1] = ptr_[i];
        }

        ptr_[0] = val;

        ++size_;
    }

    // 删除头部元素
    void pop_front() {
        // 判断顺序表是否为空
        if (empty()) {
            throw "Array is empty!";
        }
        for (int i = 1; i < size_; ++i) {
            ptr_[i - 1] = ptr_[i];
        }
        --size_;
    }

    // 获取头部元素
    int front() const {
        // 判断顺序表是否为空
        if (empty()) {
            throw "Array is empty!";
        }
        return ptr_[0];
    }

    // 根据位置插入元素
    void insert(int pos, int val) {
        if (pos < 1 || pos > size_ + 1) {
            throw "pos is invalid!";
        }

        insert_index(pos - 1, val);
    }

    // 根据位置删除元素
    void erase(int pos) {
        // 判断顺序表是否为空
        if (empty()) {
            throw "Array is empty!";
        }
        if (pos < 1 || pos > size_) {
            throw "pos is invalid!";
        }

        erase_index(pos - 1);
    }

    // 获取顺序表中有效元素的个数
    int size() const { return size_; }

    // 获取容量
    size_t cap() const { return cap_; }

    friend std::ostream& operator<<(std::ostream& os, const Array& arr);

private:
    // 扩容
    void expand(size_t new_cap) {
        // 申请新的内存空间
        int* tmp = new (std::nothrow) int[new_cap]{};
        if (!tmp) {
            throw std::bad_alloc{};
        }

        // 拷贝数据到新的内存空间
        // 只需要拷贝有效元素即可，使用size会更好一些
        // memcpy(tmp, ptr_, size_ * sizeof(int));
        std::copy(ptr_, ptr_ + size_, tmp);

        // 释放旧的内存空间
        delete[] ptr_;

        // 更新数据
        ptr_ = tmp;
        cap_ = new_cap;
    }

    // 按数组索引插入
    void insert_index(int pos, int val) {
        // 若顺序表已满
        if (full()) {
            expand(cap_ * 2);
        }
        for (int i = size_ - 1; i >= pos; --i) {
            ptr_[i + 1] = ptr_[i];
        }

        ptr_[pos] = val;
        ++size_;
    }

    // 按数组索引删除
    void erase_index(int pos) {
        // 若顺序表为空
        if (empty()) {
            throw "Array is empty!";
        }

        for (int i = pos + 1; i < size_; ++i) {
            ptr_[i - 1] = ptr_[i];
        }

        --size_;
    }
    int* ptr_;
    size_t cap_;
    int size_;
};
std::ostream& operator<<(std::ostream& os, const Array& arr) {
    if (arr.empty()) {
        return os;
    }

    for (int i = 0; i < arr.size_; ++i) {
        os << arr.ptr_[i] << " ";
    }
    return os;
}
void show(Array& arr) {
    std::cout << arr << std::endl;
    std::cout << "front: " << arr.front() << " back: " << arr.back() << std::endl;
    std::cout << "cap: " << arr.cap() << " size: " << arr.size() << std::endl;
}
int main() {
    Array my_arr{10};

    my_arr.push_back(22);
    show(my_arr);

    // 头插一个
    my_arr.push_front(33);
    show(my_arr);

    // 在指定位置插入元素
    my_arr.insert(1, 44);
    show(my_arr);

    // 在指定位置插入元素
    my_arr.insert(3, 55);
    show(my_arr);

    my_arr.insert(5, 66);
    show(my_arr);

    // 删除第一个元素
    my_arr.erase(1);
    show(my_arr);

    // 删除最后一个元素
    my_arr.erase(4);
    show(my_arr);

    for (int i = 0;i < 10;++i) {
        my_arr.push_back(22 * i);
    }
    show(my_arr);
}
