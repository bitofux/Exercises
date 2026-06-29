/*
 * PROJECT : DAY11
 * FILE    : 5.CowString.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-06-29
 * BRIEF   : String的拷贝和赋值，在之前是利用直接深拷贝
 *           进化到利用Cow，copy on write写时复制机制
 */
#include <cstddef>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <istream>
#include <ostream>
#include <vector>

class CowString {
public:
    // 空参构造
    CowString()
        : ptr_{new char[1 + 4]{}} {
        // 对这块堆内存的前4个字节进行赋值，初始赋值为0
        *(reinterpret_cast<int*>(ptr_)) = 1;

        // 将最后一个字节赋值为'\0'
        *(ptr_ + 4) = '\0';
    }

    // 字符串字面量构造
    CowString(const char* string)
        : ptr_{new char[strlen(string) + 1 + 4]{}} {
        // 对这块堆内存的前4个字节进行赋值，初始赋值为0
        *(reinterpret_cast<int*>(ptr_)) = 1;

        // 利用strncpy进行拷贝
        strncpy(ptr_ + 4, string, strlen(string) + 1);
    }

    // 拷贝构造函数
    CowString(const CowString& rhs)
        : ptr_{rhs.ptr_} {
        // 增加引用计数的值
        *(reinterpret_cast<int*>(ptr_)) += 1;
    }

    // 赋值运算符重载函数(两个已经存在的对象)
    CowString& operator=(const CowString& rhs) {
        // if (this != &rhs) {
        //     this->ptr_ = rhs.ptr_;
        //     *(reinterpret_cast<int*>(this->ptr_)) += 1;
        // }
        if (this->ptr_ != rhs.ptr_) {
            // 1. this指向的对象的引用计数-1
            *(reinterpret_cast<int*>(this->ptr_)) -= 1;
            // 2. 判断this指向的对象引用计数是否大于1
            if (*reinterpret_cast<int*>(this->ptr_) == 0) {
                delete[] this->ptr_;
            }

            // 3. 更改this->ptr_的指向
            this->ptr_ = rhs.ptr_;

            // 4. rhs的引用计数+1
            *(reinterpret_cast<int*>(rhs.ptr_)) += 1;
        }
        return *this;
    }
    ~CowString() {
        // 1. 引用计数减去1
        *(reinterpret_cast<int*>(ptr_)) -= 1;

        // 2. 若引用计数的值为0，则释放堆内存
        if (*reinterpret_cast<int*>(ptr_) == 0) {
            delete[] ptr_;
            // ptr_ = nullptr;
        }

        // 3. 若不为0，则将此对象的ptr_置为nullptr
        ptr_ = nullptr;
    }

    // 重载[]运算符(对于非const版本，编译器不知道你是读取还是写入，因此只能做防御性编程，按照写入重新分配内存)
    char& operator[](int index) {
        // 防御性检查下标
        if (index < 0 || index > size()) {
            static char ch = '\0';
            return ch;
        }

        // 需要判断当前对象的引用计数是否大于1，若不大于则无需申请新的内存
        if (*(reinterpret_cast<int*>(this->ptr_)) > 1) {
            // 1. 申请新的堆内存
            char* tmp = new char[strlen(this->ptr_ + 4) + 1 + 4]{};
            // 2. 拷贝数据 + 初始户新的引用计数
            strncpy(tmp + 4, this->ptr_ + 4, strlen(this->ptr_ + 4));
            *(reinterpret_cast<int*>(tmp)) = 1;

            // 3. 原先的引用计数-1
            *(reinterpret_cast<int*>(this->ptr_)) -= 1;

            // 4. 更新ptr_指向
            this->ptr_ = tmp;
        }

        // 5. 返回数据
        return (ptr_ + 4)[index];
    }

    // 重载[]运算符 const版本
    const char& operator[](int index) const {
        if (index < 0 || index > size()) {
            static char ch = '\0';
            return ch;
        }

        return *(this->ptr_ + 4 + index);
    }

    // 重载<<运算符
    friend std::ostream& operator<<(std::ostream& os, const CowString& string);
    // 重载>>运算符
    friend std::istream& operator>>(std::istream& is, CowString& string);

    // 获取字符串的有效字符的个数
    size_t size() const { return strlen(ptr_ + 4); }

    // 获取原始字符串的指针
    const char* c_str() const { return ptr_ + 4; }

private:
    char* ptr_;
};

// 运算符<<重载函数
std::ostream& operator<<(std::ostream& os, const CowString& string) {
    os << string.ptr_ + 4;
    return os;
}

// 运算符>>重载函数  格式化输入,遇到' ' '\n' '\t'读取终止
std::istream& operator>>(std::istream& is, CowString& string) {
    std::vector<char> vec;
    vec.reserve(1024);

    char ch = '\0';
    // while (is >> ch) {// >> 不会将' ' '\n''\t'读取到ch的，只会忽略
    //     if (ch == '\n') {
    //         break;
    //     }
    //     vec.push_back(ch);
    // }
    // 使用非格式化读取
    while ((ch = is.get()) && ch != ' ' && ch != '\n' && ch != '\t') {
        vec.push_back(ch);
    }

    // 释放string原来的数据
    delete[] string.ptr_;

    // 申请新的内存空间
    string.ptr_ = new char[vec.size() + 1 + 4]{};
    *(reinterpret_cast<int*>(string.ptr_)) = 1;

    // 拷贝数据
    strncpy(string.ptr_ + 4, vec.data(), vec.size());
    *(string.ptr_ + vec.size() + 4) = '\0';

    return is;
}

// 测试size,c_str
void test() {
    CowString str;

    std::cout << "str.size: " << str.size() << std::endl;

    CowString str1{"bitofux"};
    std::cout << "str1.size: " << str1.size() << std::endl;

    // 访问引用计数
    std::cout << *(reinterpret_cast<const int*>(str1.c_str()) - 1) << std::endl;

    std::cout << str1 << std::endl;
}

// 获取一个字符串的引用计数
int get_count(const CowString& ref_string) {
    return *(reinterpret_cast<const int*>(ref_string.c_str()) - 1);
}

// 测试拷贝函数
void test1() {
    CowString str{"bitofux"};
    // 输出引用计数和字符串
    std::cout << "count: " << get_count(str) << std::endl;
    std::cout << "str: " << str << std::endl;

    // 拷贝
    CowString str1{str};
    // 输出引用计数和字符串
    std::cout << "str1.count: " << get_count(str1) << std::endl;
    std::cout << "str1: " << str1 << std::endl;
    std::cout << "str.count: " << get_count(str) << std::endl;
    std::cout << "str: " << str << std::endl;

    {
        CowString str2{str1};
        std::cout << "str.count: " << get_count(str) << std::endl;
        std::cout << "str: " << str << std::endl;
        std::cout << "str1.count: " << get_count(str1) << std::endl;
        std::cout << "str1: " << str1 << std::endl;
        std::cout << "str2.count: " << get_count(str2) << std::endl;
        std::cout << "str2: " << str2 << std::endl;
    }
    std::cout << "str.count: " << get_count(str) << std::endl;
    std::cout << "str: " << str << std::endl;
    std::cout << "str1.count: " << get_count(str1) << std::endl;
    std::cout << "str1: " << str1 << std::endl;
}

// 测试>>运算符
void test3() {
    CowString str;
    std::cin >> str;
    std::cout << "count: " << get_count(str) << std::endl;
    std::cout << str;
}

// 测试[]运算符
void test4() {
    CowString str{"bitofux"};
    CowString str1{str};

    std::cout << "count: " << get_count(str) << std::endl;
    std::cout << "count: " << get_count(str1) << std::endl;

    std::cout << str << std::endl;
    std::cout << str1 << std::endl;

    str[0] = 'B';

    std::cout << "count: " << get_count(str) << std::endl;
    std::cout << "count: " << get_count(str1) << std::endl;

    std::cout << str << std::endl;
    std::cout << str1 << std::endl;
}

// 测试赋值运算符重载函数
void test5() {
    CowString s1{"abc"};
    CowString s2{s1};

    std::cout << "s1.str: " << s1 << std::endl;
    std::cout << "s1.count: " << get_count(s1) << std::endl;
    std::cout << "s1.str: " << s2 << std::endl;
    std::cout << "s1.count: " << get_count(s2) << std::endl;

    s1 = s2;
    std::cout << "s1.str: " << s1 << std::endl;
    std::cout << "s1.count: " << get_count(s1) << std::endl;
    std::cout << "s1.str: " << s2 << std::endl;
    std::cout << "s1.count: " << get_count(s2) << std::endl;

    CowString s3{"bcd"};
    s1 = s3;
    s2 = s3;
    std::cout << "s1.str: " << s1 << std::endl;
    std::cout << "s1.count: " << get_count(s1) << std::endl;
    std::cout << "s1.str: " << s2 << std::endl;
    std::cout << "s1.count: " << get_count(s2) << std::endl;
    std::cout << "s3.str: " << s3 << std::endl;
    std::cout << "s3.count: " << get_count(s3) << std::endl;
}
int main() {
    // test();
    // test1();
    // test3();
    test4();
    // test5();
    return 0;
}
