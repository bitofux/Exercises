/*
 * PROJECT : EXERCISES
 * FILE    : linked_stack.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-07-12
 * BRIEF   : 基于头插头删的单向链表实现的栈
 */
#include <cstddef>
#include <iostream>
#include <ostream>

class LinkedStack {
    struct Node {
        Node(int data = 0)
            : data_{data},
              next_{nullptr} {}
        int data_;
        Node* next_;
    };

public:
    LinkedStack()
        : head_{new Node{}},
          top_{head_->next_},
          size_{0} {}

    // 栈内的元素一一出栈且释放
    // 最后释放头结点
    ~LinkedStack() {
        while (top_ != nullptr) {
            head_->next_ = top_->next_;
            delete top_;
            top_ = head_->next_;
        }

        delete head_;
    }

    // 判断链栈是否为空
    bool empty() const { return top_ == nullptr; }

    // 获取链栈有效元素的个数
    size_t size() const { return size_; }

    // 获取栈顶元素
    int top() const {
        // 判断是否栈空
        if (empty()) throw "linked stack is empty!";
        return top_->data_;
    }

    // 入栈 -> 头插
    void push(int val) {
        // 定义一个新的结点
        Node* new_node = new Node{val};

        new_node->next_ = top_;
        head_->next_ = new_node;
        top_ = new_node;
        ++size_;
    }

    // 出栈 -> 头删
    void pop() {
        // 判断是否栈空
        if (empty()) throw "linked stack is empty!";
        head_->next_ = top_->next_;
        delete top_;
        top_ = head_->next_;
        --size_;
    }
    friend std::ostream& operator<<(std::ostream& os, const LinkedStack& ls);

private:
    Node* head_;
    Node* top_;
    int size_;
};
std::ostream& operator<<(std::ostream& os, const LinkedStack& ls) {
    LinkedStack::Node* p = ls.top_;

    while (p) {
        os << p->data_ << " -> ";
        p = p->next_;
    }

    os << "nullptr";

    return os;
}

void test() {
    LinkedStack ls;

    // 入栈三个元素
    ls.push(2);
    ls.push(3);
    ls.push(4);

    std::cout << ls << std::endl;
    std::cout << "top: " << ls.top() << std::endl;
    std::cout << "元素个数: " << ls.size() << std::endl;

    std::cout << "\n";

    // 出栈
    ls.pop();
    ls.pop();

    std::cout << ls << std::endl;
    std::cout << "top: " << ls.top() << std::endl;
    std::cout << "元素个数: " << ls.size() << std::endl;
}

int main() {
    test();

    return 0;
}
