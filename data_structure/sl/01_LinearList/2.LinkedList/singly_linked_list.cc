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

    // 尾插法插入结点
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

private:
    // 单向链表的数据成员
    Node* head_;  // 指向单向链表的头结点的指针
};
