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
        Node(int data = 0)
            : data_{data},
              next_{nullptr} {}
        int data_;
        Node* next_;
    };

public:
    SinglyCircleLinkedList()
        : head_{new Node} {
        // 初始阶段，尾指针和头指针都指向头结点
        tail_ = head_;
        // 将头结点也看作是尾结点，其next指向head
        tail_->next_ = head_;
    }
    ~SinglyCircleLinkedList() {
        // 定义指针p指向第一个有效结点用于删除
        Node* p = head_->next_;

        while (p != head_) {
            // head_指向p指向的下一个结点
            head_->next_ = p->next_;
            // 释放p
            delete p;
            // 重置p的值，用于删除下一个有效结点
            p = head_->next_;
        }

        // 删除头结点
        delete head_;
    }

    // 头插法
    void insertHead(int val) {
        // 构建一个新的结点
        Node* new_node = new Node{val};

        // 插入新结点
        new_node->next_ = head_->next_;
        head_->next_ = new_node;

        // 判断new_node中next指针域的值，若是head，则表明插入这个结点
        // 之前，此链表是一个空链表，需要更新tail的值
        if (new_node->next_ == head_) tail_ = new_node;
    }

    // 尾插法
    void insertTail(int val) {
        // 构建一个新的结点
        Node* new_node = new Node{val};

        // 插入新结点
        tail_->next_ = new_node;

        // 更新tail_的指向
        tail_ = new_node;
        tail_->next_ = head_;
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

                // 若删除的p指向的是尾结点，需要更新tail的值
                if (q->next_ == head_) {
                    tail_ = q;
                }
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

                // 若删除的p指向的是尾结点，需要更新tail的值
                if (q->next_ == head_) {
                    tail_ = q;
                    break;
                }

                // 若删除的不是尾结点，则需要更新p的值
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
    os << "\n";
    os << "first->" << scll.head_->next_->data_ << "\n";
    os << "tail ->" << scll.tail_->data_ << "\n";
    return os;
}

// 测试头插法
void test_insert_head() {
    SinglyCircleLinkedList scll;

    // 初始化随机设备
    std::random_device rd;

    // 使用19937算法
    std::mt19937 gen(rd());

    std::uniform_int_distribution<> distrib(1, 100);

    for (int i = 0; i < 5; ++i) {
        int val = distrib(gen);
        scll.insertHead(val);
        std::cout << scll << std::endl;
    }
}

// 测试尾插法
void test_insert_tail() {
    SinglyCircleLinkedList scll;

    // 初始化随机设备
    std::random_device rd;

    // 随机算法
    std::mt19937 gen{rd()};

    // 定义随机数的生成区间
    std::uniform_int_distribution<> distrib(1, 100);

    // 尾插10个数据
    for (int i = 0; i < 5; ++i) {
        int val = distrib(gen);
        scll.insertTail(val);
        std::cout << scll << "\n";
    }
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
    }
    std::cout << scll << std::endl;

    // 删除值为6的单个结点
    scll.remove(6);
    std::cout << scll << std::endl;

    // 插入一个尾结点，并删除，查看tail是否更新
    scll.insertTail(20);
    std::cout << scll << std::endl;
    scll.remove(20);
    std::cout << scll << std::endl;
}

void test_remove_all() {
    SinglyCircleLinkedList scll;

    // 初始化随机设备
    std::random_device rd;

    // 使用19937算法
    std::mt19937 gen(rd());

    std::uniform_int_distribution<> distrib(1, 10);

    for (int i = 0; i < 20; ++i) {
        int val = distrib(gen);
        scll.insertHead(val);
    }
    std::cout << scll << std::endl;

    // 删除值为6的单个结点
    scll.remove_all(6);
    std::cout << scll << std::endl;

    // 插入一个尾结点，并删除，查看tail是否更新
    scll.insertTail(30);
    std::cout << scll << std::endl;
    scll.remove_all(30);
    std::cout << scll << std::endl;
}
int main() {
    // 测试头插法
    // test_insert_head();

    // 测试尾插法
    // test_insert_tail();

    // 测试按值删除
    // test_remove();

    // 测试按值删除所有结点
    test_remove_all();

    return 0;
}
