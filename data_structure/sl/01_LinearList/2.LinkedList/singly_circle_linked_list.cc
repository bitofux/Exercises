/*
 * PROJECT : EXERCISES
 * FILE    : singly_circle_linked_list.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-07-02
 * BRIEF   : 单向循环链表
 */
#include <iostream>
#include <ostream>
#include <random>

class SinglyCircleLinkedList {
    struct Node {
        Node(int data)
            : data_{data},
              next_{nullptr} {}
        int data_;
        Node* next_;
    };

public:
    SinglyCircleLinkedList()
        : head_{new Node{0}} {
        // 初始阶段，尾指针和头指针都指向头结点
        tail_ = head_;
    }
    ~SinglyCircleLinkedList() {}

    // 头插法
    void insertHead(int val) {
        // 1. 构建新的结点
        Node* new_node = new Node{val};

        // 2. 当前链表若为空
        if (head_->next_ == nullptr) {
            head_->next_ = new_node;

            // 修改尾指针的指向，指向尾结点
            tail_ = new_node;
            // 尾结点的指针域要指向头结点
            tail_->next_ = head_;

        } else {  // 若不为空

            new_node->next_ = head_->next_;
            head_->next_ = new_node;
        }
    }

    // 尾插法
    void insertTail(int val) {
        // 1. 构建新的结点
        Node* new_node = new Node{val};

        // 2. 判断当前链表是否为空
        if (head_->next_ == nullptr) {
            head_->next_ = new_node;
            tail_ = new_node;

            // 修改尾指针的指向为头结点
            tail_->next_ = head_;
        } else {  // 若不为空
            tail_->next_ = new_node;
            new_node->next_ = head_;
        }
    }

    // 删除值为val的结点
    void remove(int val) {
        if (head_->next_ == nullptr) {
            return;
        }

        Node* p = head_->next_;
        Node* q = head_;

        while (p != head_) {
            if (p->data_ == val) {
                q->next_ = p->next_;
                delete p;
                break;
            } else {
                q = p;
                p = p->next_;
            }
        }
    }

    // 删除值为val的全部结点
    void remove_all(int val) {
        if (head_->next_ == nullptr) {
            return;
        }
        Node* p = head_->next_;
        Node* q = head_;

        while (p != head_) {
            if (p->data_ == val) {
                q->next_ = p->next_;
                delete p;

                p = q->next_;
            } else {
                q = p;
                p = p->next_;
            }
        }
    }

    friend std::ostream& operator<<(std::ostream& os, const SinglyCircleLinkedList& scll);

private:
    Node* head_;  // 指向头结点
    Node* tail_;  // 指向尾结点
};

std::ostream& operator<<(std::ostream& os, const SinglyCircleLinkedList& scll) {
    SinglyCircleLinkedList::Node* p = scll.head_->next_;

    while (p != scll.head_) {
        os << p->data_ << " ";
        p = p->next_;
    }
    return os;
}

void test_insert_head() {
    SinglyCircleLinkedList scll;

    // 初始化随机设备
    std::random_device rd;

    // 使用19937算法
    std::mt19937 gen(rd());

    std::uniform_int_distribution<> distrib(1, 10);

    for (int i = 0; i < 20; ++i) {
        int val = distrib(gen);
        scll.insertHead(val);
        std::cout << val << " ";
    }
    std::cout << std ::endl;

    std::cout << scll << std::endl;
}
void test_remove() {
    SinglyCircleLinkedList scll;

    // 初始化随机设备
    std::random_device rd;

    // 使用19937算法
    std::mt19937 gen(rd());

    std::uniform_int_distribution<> distrib(1, 10);

    for (int i = 0; i < 20; ++i) {
        int val = distrib(gen);
        scll.insertHead(val);
        std::cout << val << " ";
    }
    std::cout << std ::endl;

    std::cout << scll << std::endl;

    scll.remove_all(6);
    std::cout << scll << std::endl;
}

int main() {
    test_remove();

    return 0;
}
