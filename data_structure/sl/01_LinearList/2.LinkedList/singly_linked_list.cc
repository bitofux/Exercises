/*
 * PROJECT : EXERCISES
 * FILE    : singly_linked_list.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-06-27
 * BRIEF   : sll 单向链表
 */
#include <iostream>

class SinglyLinkedList {
    // 结点类型
    struct Node {
        Node(int data)
            : data_{data},
              next_{nullptr} {}
        int data_;
        Node* next_;
    };

public:
    // 无参构造
    SinglyLinkedList()
        : head_{new Node{0}} {}
    // 析构函数，释放单向链表中的每一个结点
    ~SinglyLinkedList() {}

    // 尾插法插入结点O(n)
    void insertTail(int val) {
        // 1. 找到尾部结点
        Node* tail = head_;
        while (tail->next_ != nullptr) {
            tail = tail->next_;
        }

        // 2. 以val构建新的结点
        Node* new_node = new Node{val};

        // 将尾结点的next_指向新的结点
        tail->next_ = new_node;
    }

    // 头插法插入结点O(1)
    void insertHead(int val) {
#if 0
        // 0. 先构建新的结点
        Node* new_node = new Node{val};

        // 1. 若链表中除头结点之外无有效结点
        if (head_->next_ == nullptr) {
            // 1.1 将头结点的next指针域赋值为新的结点
            head_->next_ = new_node;
            // 1.2 新结点的next指针域赋值为nullptr
            new_node->next_ = nullptr;
            return;
        }

        // 2. 否则，该链表中除头结点外还有至少有一个有效结点
        // 2.1 将新结点的next指针域赋值为当前链表中第一个有效结点的地址
        new_node->next_ = head_->next_;

        // 2.2 将头结点的next指针域赋值为新结点的地址
        head_->next_ = new_node;
#endif
        // 1. 创建新的结点
        Node* new_node = new Node{val};

        // 2. 执行第一步操作
        new_node->next_ = head_->next_;

        // 3. 执行第二步操作
        head_->next_ = new_node;
    }

private:
    // 单向链表的数据成员
    Node* head_;  // 指向单向链表的头结点的指针
};
