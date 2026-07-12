/*
 * PROJECT : EXERCISES
 * FILE    : sequence_stack.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-07-10
 * BRIEF   : 顺序栈(top == 0)
 */
#include <cstddef>
#include <cstring>
#include <iostream>
#include <ostream>

class SequenceStack {
public:
    // 构造函数
    SequenceStack(size_t cap = 10)
        : cap_{cap},
          ptr_{new int[cap_]{}},
          top_{0} {}
    // 析构函数
    ~SequenceStack() {
        delete[] ptr_;
        ptr_ = nullptr;
    }

    // 栈满
    bool full() const { return top_ == cap_; }

    // 栈空
    bool empty() const { return top_ == 0; }

    // 入栈
    void push(int val) {
        // 判断栈是否满了
        if (full()) {
            // 扩容
            expand(cap_ * 2);
        }

        /*
         * 入栈：
         * 1. 写入数据
         * 2. 移动栈顶指针 +1
         */
        ptr_[top_++] = val;
    }

    // 出栈
    void pop() {
        // 判断栈是否为空
        if (empty()) {
            // 抛出异常
            throw "stack is empty!";
        }

        /*
         * 出栈：
         * 1. 移动栈顶指针 -1
         */
        --top_;
    }

    // 获取栈顶元素
    int top() const {
        // 若栈为空
        if (empty()) {
            throw "stack is empty!";
        }

        /*
         * 获取栈顶元素：
         * 1. 返回栈顶指针 - 1 的元素值
         * 栈顶指针不需要移动
         */

        return ptr_[top_ - 1];
    }

    // 获取栈的容量
    size_t cap() const { return cap_; }

    // 栈内有效元素的个数
    int size() const { return top_; }
    friend std::ostream& operator<<(std::ostream& os, const SequenceStack& ss);

private:
    // 扩容接口
    void expand(size_t new_cap) {
        // 1. 申请的内存空间
        int* tmp = new int[new_cap]{};

        // 2.将原来旧空间的数据拷贝到新空间中
        memcpy(tmp, ptr_, sizeof(int) * cap_);

        // 3. 释放掉原来的旧空间
        delete[] ptr_;

        // 4. 指向新的内存空间，更改容量的大小
        ptr_ = tmp;
        cap_ = new_cap;
    }
    size_t cap_;  // 栈的容量
    int* ptr_;    // 指向栈元素所在的内存空间，栈底
    int top_;     // 指向栈顶
};

std::ostream& operator<<(std::ostream& os, const SequenceStack& ss) {
    for (int i = ss.size()-1; i >= 0; --i) {
        std::cout << ss.ptr_[i] << " ";
    }
    std::cout << "\n";
    return os;
}
void test() {
    // 定义一个数组
    int arr[] = {21, 23, 92, 33, 45, 65, 101, 82, 91, 222};

    // 定义一个顺序栈
    SequenceStack ss{10};
    for (auto var : arr) {
        ss.push(var);
    }

    std::cout << ss;
    std::cout << "before expand cap: " << ss.cap() << " " << "size: " << ss.size() << std::endl;

    std::cout << "\n";

    ss.push(1000);
    std::cout << ss;
    std::cout << "after expand cap: " << ss.cap() << " " << "size: " << ss.size() << std::endl;

    std::cout << "\n";
    // 获取栈顶元素一次，出栈一次
    for (int i = 0; i < 3; ++i) {
        std::cout << "top: " << ss.top() << std::endl;
        ss.pop();
        std::cout << "cap: " << ss.cap() << " " << "size: " << ss.size() << std::endl;
    }
}

int main() {
    test();

    return 0;
}
