/*
 * PROJECT : EXERCISES
 * FILE    : doubly_circle_linked_queue.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-07-19
 * BRIEF   : 基于双向循环链表实现的链式队列
 */
#include <iostream>
#include <ostream>

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

public:
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
    bool empty() const { return head_->pre_ == head_; }

    // 出队(头删)
    void dequeue() {
        // 判断当前链式队列是否为空
        if (empty()) {
            throw "DoublyCircleLinkedQueue is empty!";
        }
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

        // 更新尾结点的next
        head_->pre_->next_ = new_node;

        // 更新头结点的pre
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
    friend std::ostream& operator<<(std::ostream& os, const DoublyCircleLinkedQueue& dclq);

private:
    Node* head_;
    size_t size_;
};
std::ostream& operator<<(std::ostream& os, const DoublyCircleLinkedQueue& dclq) {
    if (dclq.empty()) {
        return os;
    }
    DoublyCircleLinkedQueue::Node* p = dclq.head_->next_;

    while (p != dclq.head_) {
        os << p->data_ << " -> ";
        p = p->next_;
    }
    os << "nullptr";
    return os;
}

int main() {
    DoublyCircleLinkedQueue dclq;
    dclq.enqueue(20);
    dclq.enqueue(30);
    dclq.enqueue(40);
    dclq.enqueue(50);

    std::cout << dclq << std::endl;
    std::cout << "front: " << dclq.front() << std::endl;
    std::cout << "back: " << dclq.back() << std::endl;
    std::cout << "size: " << dclq.size() << std::endl;
    // 出队
    dclq.dequeue();
    std::cout << dclq << std::endl;
    std::cout << "front: " << dclq.front() << std::endl;
    std::cout << "back: " << dclq.back() << std::endl;
    std::cout << "size: " << dclq.size() << std::endl;

    // 入队
    dclq.enqueue(300);
    std::cout << dclq << std::endl;
    std::cout << "front: " << dclq.front() << std::endl;
    std::cout << "back: " << dclq.back() << std::endl;
    std::cout << "size: " << dclq.size() << std::endl;
}
