/*
 * PROJECT : EXERCISES
 * FILE    : circle_queue.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-07-17
 * BRIEF   : 顺序队列 -- 环形队列
 */
#include <cstddef>
#include <iostream>
#include <ostream>
#include <random>
#include <type_traits>

using std::cout;
using std::endl;

class CircleQueue {
public:
    CircleQueue(size_t capacity = 10)
        : ptr_{new int[capacity]{}},
          head_{0},
          tail_{0},
          capacity_{capacity} {}
    ~CircleQueue() {
        delete[] ptr_;
        ptr_ = nullptr;
    }

    // 队空
    bool empty() const { return tail_ == head_; }

    // 队满
    bool full() const { return ((tail_ + 1) % capacity_) == head_; }

    // 入队
    void enqueue(int val) {
        // 判断是否队满
        if (full()) {
            // 扩容
            expand(capacity_ * 2);
        }
        // 入队
        ptr_[tail_] = val;

        // 更新队尾指针的值
        tail_ = (tail_ + 1) % capacity_;
    }

    // 出队
    void dequeue() {
        // 判断是否队空
        if (empty()) {
            throw "circle_queue is empty!";
        }

        // 更新队头指针的值
        head_ = (head_ + 1) % capacity_;
    }

    // 获取队头元素
    int head() const { return ptr_[head_]; }

    // 获取队尾元素
    int tail() const { return ptr_[(tail_ - 1 + capacity_) % capacity_]; }

    // 获取有效元素的个数
    int size() const { return ((tail_ - head_) + capacity_) % capacity_; }

    int size() {
        int size = 0;
        int p = head_;
        while (p != tail_) {
            ++size;
            p = (p + 1) % capacity_;
        }

        return size;
    }

    // 容量
    size_t cap() const { return capacity_; }

    friend std::ostream& operator<<(std::ostream& os, const CircleQueue& cq);

private:
    void expand(size_t cap) {
        // 创建新的内存空间
        int* tmp = new int[cap]{};

        int index = 0;
        while (!empty()) {
            tmp[index] = ptr_[head_];
            // 更新队头指针的值
            head_ = (head_ + 1) % capacity_;
            index++;
        }

        // 释放旧环形队列所在的内存空间
        delete[] ptr_;

        // 更新新环形队列的值
        ptr_ = tmp;
        head_ = 0;
        tail_ = index;
        capacity_ = cap;
    }
    int* ptr_;
    int head_;
    int tail_;
    size_t capacity_;
};
std::ostream& operator<<(std::ostream& os, const CircleQueue& cq) {
    // 若环形队列为空
    if (cq.empty()) {
        return os;
    }

    // 遍历不更新head_的值，因此使用p来代替head_
    int p = cq.head_;
    while (p != cq.tail_) {
        // 输出当前p索引在当前数组中的值
        os << cq.ptr_[p] << " ";
        // 更新p
        p = (p + 1) % cq.capacity_;
    }

    return os;
}

int main() { return 0; }
