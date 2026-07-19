/*
 * PROJECT : EXERCISES
 * FILE    : singly_linked_queue.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-07-18
 * BRIEF   : 基于单向链表实现的链式队列
 */
#include <iostream>
#include <ostream>
#include <type_traits>

class SinglyLinkedQueue {
    struct Node {
        Node(int data = 0)
            : data_{data},
              next_{nullptr} {}
        int data_;
        Node* next_;
    };

public:
    SinglyLinkedQueue()
        : head_{new Node{}},
          tail_{head_},
          size_{0} {}
    ~SinglyLinkedQueue() {
        Node* p = head_->next_;

        while (p) {
            head_->next_ = p->next_;
            delete p;
            p = head_->next_;
        }

        delete head_;
    }

    // 判断链式队列是否为空
    bool empty() const { return head_ == tail_; }

    // 出队 -- 单向链表的头删
    void dequeue() {
        // 判断链式队列是否为空
        if (empty()) {
            throw "linked_queue is empty!";
        }

        // 定义指针p指向队头
        Node* p = head_->next_;

        // 队头指针指向下一个元素
        head_->next_ = p->next_;

        // 释放队头
        delete p;

        // 更新size_的值
        --size_;
    }

    // 入队 -- 单向链表的尾插
    void enqueue(int val) {
        // 定义新结点
        Node* new_node = new Node{val};

        // 插入新结点
        tail_->next_ = new_node;

        // tail_指向新尾结点
        tail_ = new_node;

        // 更新size_的值
        ++size_;
    }

    // 获取队头元素
    int front() const {
        // 判断队列是否为空
        if (empty()) {
            throw "singly_linked_queue is empty!";
        }
        return head_->next_->data_;
    }

    // 获取队尾元素
    int back() const {
        // 判断队列是否为空
        if (empty()) {
            throw "singly_linked_queue is empty!";
        }
        return tail_->data_;
    }

    // 获取有效元素的个数
    int size() const { return size_; }

    friend std::ostream& operator<<(std::ostream& os, const SinglyLinkedQueue& slq);

private:
    Node* head_;
    Node* tail_;
    int size_;
};

std::ostream& operator<<(std::ostream& os, const SinglyLinkedQueue& slq) {
    if (slq.empty()) {
        return os;
    }

    SinglyLinkedQueue::Node* p = slq.head_->next_;

    while (p) {
        std::cout << p->data_ << " -> ";
        p = p->next_;
    }
    std::cout << "nullptr";
    return os;
}

int main() {
    SinglyLinkedQueue slq;

    slq.enqueue(20);
    slq.enqueue(30);
    slq.enqueue(40);
    slq.enqueue(50);

    std::cout << slq << std::endl;
    std::cout << "front: " << slq.front() << std::endl;
    std::cout << "back: " << slq.back() << std::endl;
    std::cout << "size: " << slq.size() << std::endl;

    slq.dequeue();

    std::cout << slq << std::endl;
    std::cout << "front: " << slq.front() << std::endl;
    std::cout << "back: " << slq.back() << std::endl;
    std::cout << "size: " << slq.size() << std::endl;

    slq.enqueue(100);
    std::cout << slq << std::endl;
    std::cout << "front: " << slq.front() << std::endl;
    std::cout << "back: " << slq.back() << std::endl;
    std::cout << "size: " << slq.size() << std::endl;

    return 0;
}
