/*
 * PROJECT : EXERCISES
 * FILE    : 12.dynamic_memory_alloc.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-03-04
 * BRIEF   : C++中的动态内存分配:new operator/operator new/placement new
 */

/*
 * 1. new operator
 *  调用new操作符的时候做两件事，这两件事不可分割
 *  1. 调用operator new函数分配内存空间
 *  2. 调用构造函数构造对象
 * 这两件事我们都可自定义，但这两步骤不可分割
 * 2. delete operator
 *  调用delete操作符的时候做两件事，这两件事不可分割
 *  1. 调用析构函数销毁对象
 *  2. 释放对象所占的内存空间
 * 这两件事也可自定义，但这两个步骤不可分割*/

/*
 * 1. operator new
 *  new操作符重载函数，C++库中的new操作符重载函数是弱符号，自定义的全局new操作符重载函数的符号是强符号
 *  因此，当你有自定义的new操作符重载函数的时候，不会继续调用C++库中的new操作符重载函数,delete一样
 *
 *  operator new函数的主要目的就是 分配内存空间
 *
 *  operator new[]  operator delete[] 与operator
 * new都是一样的，通过自定义这类函数，可以搞清楚delete与delete[]的区别*/

#include <cstddef>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <ostream>

// 重载new操作符 operator new
void* operator new(size_t size) {
    void* p = malloc(size);
    return p;
}
// 重载delete操作符 operator delete
void operator delete(void* p) { free(p); }

// 重载new[]
void* operator new[](size_t size) {
    void* p = malloc(size);
    return p;
}

// 重载delete[]
void operator delete[](void* p) { free(p); }

class String;
// placement new 自定义
void* operator new(size_t size, String* p) {
    std::cout << "placement new\n";
    return p;
}
class String {
public:
    // 构造函数
    String(const char* data = "") {
        std::cout << "String(const char*)\n";
        if (data == nullptr) {
            data_ = new char[1]{};
        } else {
            data_ = new char[strlen(data) + 1]{};
            std::strcpy(data_, data);
        }
    }
    // 析构函数
    ~String() {
        std::cout << "~String()\n";
        delete[] data_;
    }

public:
    friend std::ostream& operator<<(std::ostream& os, const String& str);

private:
    char* data_;
};

std::ostream& operator<<(std::ostream& os, const String& str) {
    os << str.data_;
    return os;
}

int main() {
    // String* ptr {new String{"bfx"}};
    // 1. 分配内存
    String* ptr{reinterpret_cast<String*>(operator new(sizeof(String)))};
    // 2. 构造对象 -- placement new
    new (ptr) String{"bfx"};

    // delete ptr;
    // 1. 调用析构函数
    ptr->~String();
    // 2. 释放内存
    free(ptr);

    void* p1{std::malloc(sizeof(int))};
    new (p1) int{10};
    std::cout << "*p1: " << *(static_cast<int*>(p1)) << "\n";
    return 0;
}
