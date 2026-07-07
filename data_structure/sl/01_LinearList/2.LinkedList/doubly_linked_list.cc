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

    // 尾插法
    void insertTail(int val) {
        // 1. 定义寻找尾结点的指针p
        Node* p = head_;
        while (p->next_ != nullptr) {
            p = p->next_;
        }

        // 2. 构建新的结点new_node
        Node* new_node = new Node{val};

        // 3. 执行插入
        p->next_ = new_node;
        new_node->pre_ = p;
    }

    // 按值删除单个结点
    void remove(int val) {
        // 若链表无有效结点
        if (head_->next_ == nullptr) {
            return;
        }
        // 定义一个新的指针p
        Node* p = head_->next_;

        // 循环找到要删除的结点
        while (p != nullptr) {
            // 判断当前结点的数据域是否与val相等，若相等则执行删除
            if (p->data_ == val) {
                p->pre_->next_ = p->next_;
                // 若删除的结点不是尾结点
                if (p->next_ != nullptr) {
                    p->next_->pre_ = p->pre_;
                }

                delete p;
                break;
            } else {
                p = p->next_;
            }
        }
    }
    // 按值删除多个结点
    void remove_all(int val) {
        // 若链表无有效结点
        if (head_->next_ == nullptr) {
            return;
        }
        // 定义一个新的指针p
        Node* p = head_->next_;

        // 循环找到要删除的结点
        while (p != nullptr) {
            // 判断当前结点的数据域是否与val相等，若相等则执行删除
            if (p->data_ == val) {
                p->pre_->next_ = p->next_;
                // // 若删除的结点不是尾结点
                // if (p->next_ != nullptr) {
                //     p->next_->pre_ = p->pre_;
                //     Node* q = p->next_;
                //     delete p;
                //     p = q;
                // } else {// 若是尾结点
                //     delete p;
                //     break;
                // }

                // 若p指向的不是尾结点，更新下一个结点的pre
                if (p->next_ != nullptr) {
                    p->next_->pre_ = p->pre_;
                }

                Node* q = p->next_;
                delete p;
                p = q;
            } else {
                p = p->next_;
            }
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

// 测试尾插法
void test_insert_tail() {
    DoublyLinkedList dll;

    std::random_device rd;

    std::mt19937 gen{rd()};

    std::uniform_int_distribution<> distrib(1, 100);

    for (int i = 0; i < 5; ++i) {
        dll.insertTail(distrib(gen));
    }

    std::cout << dll << "\n";
}

// 测试按值删除单个结点
void test_remove() {
    DoublyLinkedList dll;

    dll.insertTail(10);
    dll.insertTail(20);
    dll.insertTail(50);

    dll.remove(50);
    std::cout << dll << std::endl;
}

// 测试按值删除多个结点
void test_remove_all() {
    DoublyLinkedList dll;

    dll.insertTail(10);
    dll.insertTail(20);
    dll.insertTail(50);
    dll.insertTail(20);

    dll.insertTail(20);

    dll.remove_all(20);

    std::cout << dll << std::endl;
}

int main() {
    // test_insert_head();

    // test_insert_tail();

    // test_remove();

    test_remove_all();

    return 0;
}
