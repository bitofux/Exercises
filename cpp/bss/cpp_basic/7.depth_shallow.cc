/*
 * PROJECT : EXERCISES
 * FILE    : 7.depth_shallow.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-02-13
 * BRIEF   : 浅拷贝和深拷贝 浅赋值和深赋值
 */
#include <cstring>
#include <iostream>

namespace bitofux {
class string {
public:
    string(const char* data = nullptr)
        : data_{new char[strlen(data) + 1]{}} {
        strcpy(data_, data);
    }
    // 拷贝构造函数 -> 用于深拷贝
    string(const string& other)
        : data_{new char[strlen(other.data_) + 1]{}} {
        strcpy(data_, other.data_);
    }
    // 赋值运算符重载函数 -> 用于深赋值
    string& operator=(const string& other) {
        if (this != &other) {
            // 1. 申请新的内存空间
            char* tmp = new char[strlen(other.data_) + 1]{};
            if (!tmp) {
                std::cerr << "new failed\n";
                return *this;
            }
            // 2. 释放原来的内存空间
            delete[] this->data_;
            this->data_ = tmp;

            // 3. 将other的数据拷贝到this
            strcpy(this->data_, other.data_);
            return *this;
        }
        return *this;
    }
    ~string() {
        delete[] data_;
        data_ = nullptr;
    }

public:
    char* operator*() { return data_; }
    const char* operator*() const { return data_; }

private:
    char* data_;
};
}  // namespace bitofux

int main() {
    using bitofux::string;
    string s1{"bfx_one"};
    std::cout << "s1: " << (void*)*s1 << "\n";

    // 测试深拷贝
    string s2{s1};
    std::cout << "s2: " << (void*)*s2 << "\n";

    // 测试深赋值
    string s3 {"hello"};
    string s4 {"world"};
    s3 = s4;
    std::cout << "s3: " << (void*)*s3 << "\n";
    std::cout << "s4: " << (void*)*s4 << "\n";
}
