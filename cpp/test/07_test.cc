/****************************************************
 * @file    07_test.cc
 * @brief   实现一个顺序栈
 * @author  bitofux
 * @date    2025-09-05
 ****************************************************/
#include <condition_variable>
#include <iostream>
#include <iterator>
class SeqStack {
public:
    // 构造函数是可以有参数的,因此构造函数可以重载
    SeqStack(const int size = 10) {
        _pstack = new int[size]{};
        _top = -1;
        _size = size;
    }

    // 自定义拷贝构造函数
    // _pstack除非对象析构,否则不可能为nullptr
    SeqStack(const SeqStack& other) {
        _pstack = new int[other._size]{};
        for (int i = 0; i < other._size; ++i) {
            _pstack[i] = other._pstack[i];
        }
        _size = other._size;
        _top = other._top;
    }
    // 自定义赋值运算符重载函数
    SeqStack& operator=(const SeqStack& other) {
        if (this != &other) {
            delete[] _pstack;
            _pstack = new int[other._size]{};
            for (int i = 0; i < other._size; ++i) {
                _pstack[i] = other._pstack[i];
            }
            _top = other._top;
            _size = other._size;
        }
        return *this;
    }
    // // 初始化顺序栈
    // void init(const int size = 10) {
    //     _pstack = new int[size]{};
    //     _top = -1;
    //     _size = size;
    // }

    // 析构函数
    ~SeqStack() {
        delete[] _pstack;
        _pstack = nullptr;
    }

    // // 销毁顺序栈
    // void release() {
    //     delete[] _pstack;
    //     _pstack = nullptr;
    // }

    // 元素入栈
    void push(int element) {
        if (full()) {
            resize(_size * 2);
        }
        _pstack[++_top] = element;
    }

    // 元素出栈
    void pop() {
        if (empty()) {
            return;
        }
        --_top;
    }

    // 取栈顶元素
    int top() { return _pstack[_top]; }

    // 判断栈是否满了
    bool full() const { return _top == _size - 1; }
    bool empty() const { return _top == -1; }

private:
    int* _pstack;  // 动态开辟数组,存储顺序栈的元素
    int _top;      // 指向栈顶的元素
    int _size;     // 顺序栈的元素个数
    // 顺序栈的扩容
    void resize(int size) {
        int* tmp = new int[size]{};
        for (int i = 0; i < _size; i++) {
            tmp[i] = _pstack[i];
        }  // 不使用memcpy的原因是它是按照字节拷贝,这会导致浅拷贝的问题
        delete[] _pstack;
        _pstack = tmp;
        _size = size;
    }
};
