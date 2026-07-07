/*
 * PROJECT : EXERCISES
 * FILE    : 01.string_v1.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-07-05
 * BRIEF   : 第一版本的string实现
 */
#include <cstring>
#include <stdexcept>

class String {
public:
    explicit String(const char* s) {
        ptr_ = new char[strlen(s) + 1]{};
        if (ptr_ == nullptr) {
            throw std::invalid_argument{"argument error"};
        }

        // 拷贝数据
        std::strncpy(ptr_, s, strlen(s) + 1);
    }

    ~String() {
        delete[] ptr_;
        ptr_ = nullptr;
    }

    // 禁用拷贝构造函数和赋值运算符重载函数
    String(const String&) = delete;
    String& operator=(const String&) = delete;

    // 返回存储字符串堆内存的首地址
    const char* c_str() { return ptr_; }

private:
    char* ptr_;
};

int main() {

}
