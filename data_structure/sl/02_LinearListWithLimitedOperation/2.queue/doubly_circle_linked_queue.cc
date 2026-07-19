/*
 * PROJECT : EXERCISES
 * FILE    : doubly_circle_linked_queue.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-07-19
 * BRIEF   : 基于双向循环链表实现的链式队列
 */
#include <iostream>

class DoublyCircleLinkedQueue {
    struct Node {
        Node(int data = 0)
            : data_{data},
              pre_{nullptr},
              next_{nullptr} {}
        int data_;
        Node* pre_;
        Node* next_;
    };

    DoublyCircleLinkedQueue()
        : head_{new Node{}},
          size_{0} {
        head_->next_ = head_;
        head_->pre_ = head_;
    }
    ~DoublyCircleLinkedQueue() {
        Node* p = head_->next_;
        while (p != head_) {
            head_->next_ = p->next_;
            delete p;
            p = head_->next_;
        }

        delete head_;
        head_ = nullptr;
    }

    // 判断当前链式队列是否为空
    bool empty() const { return head_->pre_ = head_; }

    // 出队(头删)
    void dequeue() {
        // 定义指针p指向第一个有效结点(队头结点)
        Node* p = head_->next_;

        // 头结点的next指向第一个有效结点的后一个结点
        // 后一个结点成为新的有效结点
        head_->next_ = p->next_;

        // 新的有效结点的pre指向头结点
        p->next_->pre_ = head_;

        // 释放p指向的结点
        delete p;

        // 元素个数自身减1
        --size_;
    }

    // 入队(尾插)
    void enqueue(int val) {
        // 定义新的结点
        Node* new_node = new Node{val};

        // 更新新结点的指向
        // 新结点只要成功插入就是新的尾结点，那么它的next指向头结点
        new_node->next_ = head_;
        // 它的pre指向旧的尾结点
        new_node->pre_ = head_->pre_;

        // 更新头结点pre的值，它需要指向新的尾结点
        head_->pre_ = new_node;

        // 元素个数自身加1
        ++size_;
    }

    // 获取队头元素
    int front() const {
        // 判断队列是否为空
        if (empty()) {
            throw "doubly_circle_linked_queue is empty!";
        }
        return head_->next_->data_;
    }

    // 获取队尾元素
    int back() const {
        // 判断队列是否为空
        if (empty()) {
            throw "doubly_circle_linked_queue is empty!";
        }

        return head_->pre_->data_;
    }

    // 获取元素个数
    int size() const { return size_; }

private:
    Node* head_;
    size_t size_;
};
