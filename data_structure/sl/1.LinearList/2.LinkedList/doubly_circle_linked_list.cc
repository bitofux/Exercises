/*
 * PROJECT : EXERCISES
 * FILE    : doubly_circle_linked_list.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-07-06
 * BRIEF   : 双向循环链表
 */
#include <cerrno>
#include <iostream>
#include <random>

class DoublyCircleLinkedList {
    struct Node {
        Node(int data = 0)
            : data_{data},
              next_{nullptr},
              pre_{nullptr} {}
        int data_;
        Node* next_;
        Node* pre_;
    };

public:
    DoublyCircleLinkedList()
        : head_{new Node{0}} {
        // 头结点也是尾结点
        head_->next_ = head_;
        head_->pre_ = head_;
    }
    ~DoublyCircleLinkedList() {
        // 退化成单向循环链表的析构

        // 1. 定义新的指针指向要被删除的结点
        Node* p = head_->next_;

        // 2. 先循环删除链表中所有有效结点(不包括头结点)
        while (p != head_) {
            head_->next_ = p->next_;
            delete p;
            p = head_->next_;
        }

        // 3. 删除头结点
        delete head_;
        head_ = nullptr;
    }
    friend std::ostream& operator<<(std::ostream& os, const DoublyCircleLinkedList& dcll);

    // 头插法
    void insertHead(int val) {
        // 构建新的结点
        Node* new_node = new Node{val};

        // 更新new_node的next与pre
        new_node->next_ = head_->next_;
        new_node->pre_ = head_;

        // 头结点的next指向new_node
        head_->next_ = new_node;

        // new_node的next的pre指向自己
        new_node->next_->pre_ = new_node;
    }

    // 尾插法
    void insertTail(int val) {
        // // 循环找到当前链表中的尾结点
        // Node* p = head_;
        // while (p->next_ != head_) {
        //     p = p->next_;
        // }
        // 尾结点就是head->pre
        Node* p = head_->pre_;

        // 构建新的结点
        Node* new_node = new Node{val};

        // 更新新结点的next与pre
        new_node->next_ = head_;
        new_node->pre_ = p;

        // 更新尾结点的next，指向新的尾结点
        p->next_ = new_node;

        // 头结点的pre指向新的尾结点
        head_->pre_ = new_node;
    }

    // 按值删除单个结点
    void remove(int val) {
        // 定义新的指针指向要删除的结点
        Node* p = head_->next_;

        while (p != head_) {
            // 若p指向的结点的值等于val
            if (p->data_ == val) {
                // // p指向的不是尾结点
                // if (p->next_ != head_) {
                //     p->pre_->next_ = p->next_;
                //     p->next_->pre_ = p->pre_;
                // } else {  // 是尾结点
                //     p->pre_->next_ = p->next_;
                //     p->next_->pre_ = p->pre_;
                // }
                p->pre_->next_ = p->next_;
                p->next_->pre_ = p->pre_;
                delete p;
                break;
            } else {
                p = p->next_;
            }
        }
    }

    // 按值删除多个结点
    void remove_all(int val) {
        // 定义新指针指向第一个有效结点
        Node* p = head_->next_;

        while (p != head_) {
            if (p->data_ == val) {
                // // 若删除的是尾结点
                // if (p->next_ == head_) {
                //     p->next_->pre_ = p->pre_;
                //     p->pre_->next_ = p->next_;
                //     delete p;
                //     break;
                // } else {  // 若不是尾结点，需要重置p的值
                //     p->next_->pre_ = p->pre_;
                //     p->pre_->next_ = p->next_;
                //     // 删除结点之前，保存p->next的值
                //     Node* q = p->next_;
                //     delete p;
                //     p = q;
                // }
                p->next_->pre_ = p->pre_;
                p->pre_->next_ = p->next_;

                // // 若p指向的结点是尾结点
                // if (p->next_ == head_) {
                //     delete p;
                //     break;
                // } else {  // 若不是尾结点
                //     Node* q = p->next_;
                //     delete p;
                //     p = q;
                // }
                Node* q = p->next_;
                delete p;
                p = q;
            } else {
                p = p->next_;
            }
        }
    }

private:
    Node* head_;
};
std::ostream& operator<<(std::ostream& os, const DoublyCircleLinkedList& dcll) {
    DoublyCircleLinkedList::Node* p = dcll.head_->next_;

    os << "head node: " << "\n";
    os << "ptr: " << dcll.head_ << "\n";
    os << "pre_: " << dcll.head_->pre_ << "\n";
    os << "next_: " << dcll.head_->next_ << "\n";
    os << "\n";

    int count = 1;
    while (p != dcll.head_) {
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

// 测试头结点
void test_head() {
    DoublyCircleLinkedList dcll;
    std::cout << dcll << std::endl;
}

// 测试头插法
void test_insert_head() {
    DoublyCircleLinkedList dcll;

    dcll.insertHead(10);
    dcll.insertHead(5);
    dcll.insertHead(2);
    dcll.insertHead(33);
    dcll.insertHead(32);

    std::cout << dcll << std::endl;
}

// 测试尾插法
void test_insert_tail() {
    DoublyCircleLinkedList dcll;

    dcll.insertTail(10);
    dcll.insertTail(20);
    dcll.insertTail(30);
    dcll.insertTail(40);

    std::cout << dcll << std::endl;
}

// 测试remove
void test_remove() {
    DoublyCircleLinkedList dcll;

    dcll.insertTail(10);
    dcll.insertTail(20);
    dcll.insertTail(30);
    dcll.insertTail(40);

    dcll.remove(40);

    std::cout << dcll << std::endl;
}
void test_remove_all() {
    DoublyCircleLinkedList dcll;

    dcll.insertTail(10);
    dcll.insertTail(20);
    dcll.insertTail(30);
    dcll.insertTail(20);

    dcll.remove_all(20);

    std::cout << dcll << std::endl;
}

int main() {
    // test_head();
    // test_insert_head();
    // test_insert_tail();
    // test_remove();

    test_remove_all();
    return 0;
}
