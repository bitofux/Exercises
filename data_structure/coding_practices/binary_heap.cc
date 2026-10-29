/*
 * PROJECT : EXERCISES
 * FILE    : binary_heap.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-10-22
 * BRIEF   : 二叉堆
 */

#include <iostream>
#include <ostream>
#include <utility>

template <typename T, std::size_t CAPACITY = 5>
class MinHeap {
private:
    std::size_t capacity_;
    std::size_t size_;
    T* array_;

public:
    MinHeap()
        : capacity_{CAPACITY},
          size_{0},
          array_{new T[capacity_]{}} {}

    // 获取某节点的左孩子下标
    std::size_t left(std::size_t index) const { return 2 * index + 1; }

    // 获取某节点的右孩子下标
    std::size_t right(std::size_t index) const { return 2 * index + 2; }

    // 获取某节点的根节点下标
    std::size_t root(std::size_t index) const { return (index - 1) / 2; }

    // 插入
    void insert(T value) {
        array_[size_++] = value;

        for (std::size_t i = size_ - 1; i != 0 && array_[i] < array_[root(i)];) {
            std::swap(array_[i], array_[root(i)]);
            i = root(i);
        }
        // int i = size_ - 1;
        // for (; i != 0 && value < array_[root(i)]; i = root(i)) {
        //     array_[i] = array_[root(i)];
        // }

        // array_[i] = value;
    }

    friend std::ostream& operator<<(std::ostream& os, const MinHeap<int>& heap);
};

std::ostream& operator<<(std::ostream& os, const MinHeap<int>& heap) {
    for (int i = 0; i < heap.size_; ++i) {
        std::cout << heap.array_[i] << " ";
    }

    return os;
}

int main() {
    MinHeap<int> heap;
    heap.insert(2);
    heap.insert(2);
    heap.insert(-2);
    heap.insert(2);
    heap.insert(-1);

    std::cout << heap << "\n";
}
