/*
 * PROJECT : EXERCISES
 * FILE    : doubly_linked_list.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-07-04
 * BRIEF   : 双向链表
 */
#include <iostream>
#include <ostream>
#include <random>

class DoublyLinkedList {
    struct Node {
        Node(int data = 0)
            : data_{data},
              pre_{nullptr},
              next_{nullptr} {}
        int data_;    // 数据域
        Node* pre_;   // 指向前一个结点的指针
        Node* next_;  // 指向后一个结点的指针
    };

public:
    // 构造函数
    DoublyLinkedList()
        : head_{new Node{0}} {}
    // 析构函数
    ~DoublyLinkedList() {
        Node* p = head_;

        while (p != nullptr) {
            head_ = head_->next_;
            delete p;
            p = head_;
        }
    }

    // 头插法
    void insertHead(int val) {
        // 构建新的结点
        Node* new_node = new Node{val};

        // 更新new_node的next与pre
        new_node->next_ = head_->next_;
        new_node->pre_ = head_;

        // 更新head的指向
        head_->next_ = new_node;

        // 判断new_node->next是否为nullptr
        if (new_node->next_ != nullptr) {
            new_node->next_->pre_ = new_node;
        }
    }

private:
    friend std::ostream& operator<<(std::ostream& os, const DoublyLinkedList& dll);
    Node* head_;  // 指向头结点的指针
};

std::ostream& operator<<(std::ostream& os, const DoublyLinkedList& dll) {
    DoublyLinkedList::Node* p = dll.head_->next_;

    os << "head node: " << "\n";
    os << "ptr: " << dll.head_ << "\n";
    os << "pre_: " << dll.head_->pre_ << "\n";
    os << "next_: " << dll.head_->next_ << "\n";
    os << "\n";

    int count = 1;
    while (p != nullptr) {
        os << "node " << count << ": \n";
        os << "ptr: " << p << "\n";
        os << "data: " << p->data_ << "\n";
        os << "pre_: " << p->pre_ << "\n";
        os << "next_: " << p->next_ << "\n";
        os << "\n";
        p = p->next_;
        ++count;
    }

    return os;
}

// 测试头插法
void test_insert_head() {
    DoublyLinkedList dll;

    std::random_device rd;

    std::mt19937 gen{rd()};

    std::uniform_int_distribution<> distrib(1, 100);

    for (int i = 0; i < 5; ++i) {
        dll.insertHead(distrib(gen));
    }

    std::cout << dll << "\n";
}

int main() {
    test_insert_head();

    return 0;
}
