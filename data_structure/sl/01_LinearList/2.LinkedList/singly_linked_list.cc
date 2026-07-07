/*
 * PROJECT : EXERCISES
 * FILE    : singly_linked_list.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-06-27
 * BRIEF   : sll 单向链表
 */
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <ostream>

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
    ~SinglyLinkedList() {
        // 定义一个新的指针p指向head
        Node* p = head_;

        // 循环删除结点(包括头结点)
        while (head_ != nullptr) {
            // 保存下一个有效结点，使其成为头结点
            head_ = head_->next_;

            // 删除旧的头结点
            delete p;

            // 使其p指向新的头结点，以便删除
            p = head_;
        }

        head_ = nullptr;
    }

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

    // 按值删除单个结点
    void remove(int val) {
        // 判断当前链表是否有有效结点
        if (head_->next_ == nullptr) {
            return;
        }
        // q初始指向头结点
        Node* q = head_;
        // p初始指向第一个有效结点
        Node* p = head_->next_;

        // 循环遍历找到值为val的结点
        while (p != nullptr) {
            // 判断当前p指向的结点的数据域为val
            if (p->data_ == val) {
                // q指向的结点的next域修改为p指向结点的next域值
                q->next_ = p->next_;
                // 释放p指向的结点
                delete p;
                break;
            } else {  // 若当前p指向的结点的数据域不为val
                // q向前进一个结点，也就是p的值
                q = p;

                // p向前进一个结点，也就是p->next的值
                p = p->next_;
            }
        }
    }

    // 按值删除多个结点
    void remove_all(int val) {
        // 判断当前链表是否有有效结点
        if (head_->next_ == nullptr) {
            return;
        }
        Node* q = head_;
        Node* p = head_->next_;

        while (p != nullptr) {
            if (p->data_ == val) {
                q->next_ = p->next_;

                delete p;

                // 重置p的值，指向原来p的下一个结点(next)
                p = q->next_;
            } else {
                q = p;
                p = p->next_;
            }
        }
    }

    // 搜索
    bool find(int val) const {
        // p指向第一个有效结点
        Node* p = head_->next_;

        // 遍历整个链表
        while (p != nullptr) {
            // 若数据域等于val
            if (p->data_ == val) {
                return true;
            } else {           // 若不等于
                p = p->next_;  // 移动p的指向
            }
        }

        return false;
    }
    friend std::ostream& operator<<(std::ostream& os, const SinglyLinkedList& sll);

private:
    // 单向链表的数据成员
    Node* head_;  // 指向单向链表的头结点的指针
};
std::ostream& operator<<(std::ostream& os, const SinglyLinkedList& sll) {
    SinglyLinkedList::Node* p = sll.head_->next_;
    while (p != nullptr) {
        os << p->data_ << " ";
        p = p->next_;
    }

    return os;
}

// 1. 测试尾插法
void test_insert_tail() {
    // 创建一个链表
    SinglyLinkedList sll{};

    srand(time(nullptr));

    // 头插法插入10个随机数据
    for (int i = 0; i < 10; ++i) {
        int val = rand() % 100 + 1;
        sll.insertTail(val);
        std::cout << val << " ";
    }
    std::cout << "\n";

    // 输出链表的数据
    std::cout << sll << std::endl;
}

// 2. 测试头插法
void test_insert_head() {
    // 创建一个链表
    SinglyLinkedList sll{};

    srand(time(nullptr));

    // 头插法插入10个随机数据
    for (int i = 0; i < 10; ++i) {
        int val = rand() % 100 + 1;
        sll.insertHead(val);
        std::cout << val << " ";
    }
    std::cout << "\n";

    // 输出链表的数据
    std::cout << sll << std::endl;
}

// 3. 测试remove
void test_remove() {
    SinglyLinkedList sll;

    for (int i = 0; i < 10; ++i) {
        sll.insertHead(i * 23);
    }

    std::cout << sll << std::endl; /* 207 184 161 138 115 92 69 46 23 0 */

    // 删除161 207 0
    sll.remove(161);
    std::cout << sll << std::endl;

    sll.remove(207);
    std::cout << sll << std::endl;

    sll.remove(0);
    std::cout << sll << std::endl;
}

// 4. 测试remove_all
void test_remove_all() {
    SinglyLinkedList sll;

    for (int i = 11; i < 20; ++i) {
        sll.insertTail(i * 3);
    }

    std::cout << sll << std::endl; /* 33 36 39 42 45 48 51 54 57 */

    // 头部插入42
    sll.insertHead(42);

    // 尾部插入42
    sll.insertTail(42);

    std::cout << sll << std::endl;

    // 删除42，所有等于42的结点全部删除
    sll.remove_all(42);

    std::cout << sll << std::endl;
}

// 测试find
void test_find() {
    SinglyLinkedList sll;

    sll.insertHead(20);
    sll.insertTail(30);

    std::cout << sll.find(20) << std::endl;
}
int main() {
    // 1. 测试尾插法
    // test_insert_tail();

    // 2. 测试头插法
    // test_insert_head();

    // 3. 测试remove
    // test_remove();

    // 4. 测试remove_all
    // test_remove_all();

    // 5. 测试搜索
    test_find();

    return 0;
}
