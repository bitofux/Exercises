/*
 * PROJECT : EXERCISES
 * FILE    : 8.operator_overload.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-03-03
 * BRIEF   : 运算符重载的简单理解
 */
#include <cstring>
#include <iostream>

namespace bfx {
class string {
public:
    // 单个参数构造
    string(const char* data = "") {
        if (strcmp(data, "") == 0) {
            data_ = new char[1]{};
            strcpy(data_, data);
            length_ = 0;
        } else {
            length_ = strlen(data) + 1;
            data_ = new char[length_]{};
            strcpy(data_, data);
        }
    }
    // 拷贝构造
    string(const string& other)
        : data_{new char[strlen(other.data_) + 1]{}},
          length_(other.length_) {
        strcpy(data_, other.data_);
    }
    // 析构函数
    ~string() {
        delete[] data_;
        data_ = nullptr;
    }
    // 赋值运算符重载
    string& operator=(const string& other) {
        if (this != &other) {
            // 1.申请新的内存空间
            char* tmp = new char[strlen(other.data_) + 1]{};
            if (!tmp) {
                std::cerr << "new failed\n";
                return *this;
            }
            // 2. 释放原来的内存
            delete[] this->data_;
            data_ = tmp;

            // 3. 拷贝数据
            strcpy(this->data_, other.data_);
            length_ = other.length_;
            return *this;
        }
        return *this;
    }
    // 输出运算符重载 <<
    friend std::ostream& operator<<(std::ostream& os, const string& other);
    // 指针运算符重载 *
    const char& operator*() { return *data_; }
    const char& operator*() const { return *data_; }
    // 下标访问运算符重载[]
    const char& operator[](int index) {
        // 1. 检查下标是否合法
        if (index < length_) {
            return *(data_ + index);
        }
        return *(data_ + length_);
    }
    const char& operator[](int index) const {
        // 1. 检查下标是否合法
        if (index < length_) {
            return *(data_ + index);
        }
        return *(data_ + length_);
    }

private:
    char* data_;
    unsigned int length_;
};

std::ostream& operator<<(std::ostream& os, const string& other) {
    os << other.data_;
    return os;
}
}  // namespace bfx

int main() {
    using namespace bfx;

    // 测试输出运算符
    string s1;
    std::cout << "s1: " << s1 << "\n";
    string s2{"bfx"};
    std::cout << "s2: " << s2 << "\n";

    // 测试下标访问运算符
    std::cout << "s1[2]: " << s2[2] << "\n";

    // 测试*运算符
    std::cout << "*s2: " << *s2 << "\n";

    return 0;
}
