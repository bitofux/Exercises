/*
 * PROJECT : EXERCISES
 * FILE    : 11.class_template.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-03-04
 * BRIEF   : 类模板
 */
#include <iostream>

// list类模板的前向声明
template <typename T>
class list;
// 链表节点类模板
template <typename T>
class list_node {
    friend class list<T>;

public:
    list_node();
    list_node(T data, list_node<T>* next);

private:
    T data_;
    list_node<T>* next_;
};

template <typename T>
list_node<T>::list_node() {
    data_ = T{};
    next_ = nullptr;
}

template <typename T>
list_node<T>::list_node(T data, list_node<T>* next) {
    data_ = data;
    next_ = next;
}

// 链表类模板
template <typename T>
class list {
public:
    list();
    list(list_node<T>* first, list_node<T>* last, size_t size);
    bool push_back(T data);
    void show_list() {
        list_node<T>* start = first_->next_;
        while (start) {
            std::cout << start->data_ << " ";
            start = start->next_;
        }
        std::cout << "\n";
    }

private:
    list_node<T>* first_;
    list_node<T>* last_;
    size_t size_;
};

template <typename T>
list<T>::list() {
    list_node<T>* head = new list_node<T>{};
    first_ = last_ = head;
    size_ = 0;
}

template <typename T>
list<T>::list(list_node<T>* first, list_node<T>* last, size_t size) {
    first_ = last_ = first;
    size_ = size;
}

template <typename T>
bool list<T>::push_back(T data) {
    list_node<T>* tmp = new list_node<T>{};
    if (!tmp) return false;
    tmp->data_ = data;
    tmp->next_ = nullptr;
    last_->next_ = tmp;
    last_ = tmp;
    ++size_;
    return true;
}

int main() {
    list<char> mylist;

    for (int i = 0; i < 10; ++i) {
        mylist.push_back('a' + i);
    }
    mylist.show_list();
}
