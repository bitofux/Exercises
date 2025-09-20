/****************************************************
 * @file    5_3_string_iterator.cc
 * @brief   为String类型实现一个简单的迭代器
 * @author  bitofux
 * @date    2025-09-18
 ****************************************************/
#include <cstring>
#include <iostream>

class String {
public:
    String(const char* data = nullptr) {
        if (nullptr == data) {
            _data = new char[1]{'\0'};
        } else {
            _data = new char[std::strlen(data) + 1]{};
            std::strcpy(_data, data);
        }
    }
    String(const String& src) {
        _data = new char[std::strlen(src._data) + 1]{};
        std::strcpy(_data, src._data);
    }
    String& operator=(const String& src) {
        if (this == &src) return *this;
        if (std::strlen(src._data) > std::strlen(_data)) {
            delete[] _data;
            _data = new char[std::strlen(src._data) + 1]{};
            std::strcpy(_data, src._data);
        } else {
            std::strcpy(_data, src._data);
            _data[std::strlen(src._data)] = '\0';
        }
        return *this;
    }
    // 获取String有效字符的个数
    int length() const { return std::strlen(_data); }
    // 获取当前字符串所在的内存空间的首地址
    const char* c_str() const { return _data; }
    // 比较运算符的重载
    bool operator>(const String& src) const { return (std::strcmp(_data, src._data) > 0); }
    bool operator<(const String& src) const { return (std::strcmp(_data, src._data) < 0); }
    bool operator==(const String& src) const { return (std::strcmp(_data, src._data) == 0); }
    // []运算符的重载
    char& operator[](int i) { return _data[i]; }
    const char& operator[](int i) const { return _data[i]; }

    // String简单迭代器
    // 其实就是内部里封装了一个类类型
    // 每个类类型对象保存了当前容器的各个位置的信息
    class iterator {
    public:
        iterator(char* ptr)
            : _ptr{ptr} {}
        // 当前迭代器的运算符!=重载函数
        bool operator!=(const iterator& src) const { return _ptr != src._ptr; }
        // 前自增
        iterator& operator++() {
            this->_ptr++;
            return *this;
        }
        // *运算符重载
        char& operator*() { return *_ptr; }

    private:
        char* _ptr;
    };

    // 当前容器类String提供begin和end方法
    // begin保存的就是一个临时的iterator对象,其内部的数据是指向了
    // 当前容器类的首个元素
    iterator begin() const { return iterator{_data}; }
    // 指向容器类的末尾有效元素的后继位
    iterator end() const { return iterator{_data + length()}; }

private:
    char* _data;
    friend std::ostream& operator<<(std::ostream& os, const String& src);
    friend String operator+(const String& lhs, const String& rhs);
};

std::ostream& operator<<(std::ostream& os, const String& src) { return (os << src._data); }
// 提供一个全局的运算符+的重载
String operator+(const String& lhs, const String& rhs) {
    char* ptmp = new char[std::strlen(lhs._data) + std::strlen(rhs._data) + 1]{};
    std::strcat(ptmp, lhs._data);
    std::strcat(ptmp + lhs.length(), rhs._data);
    String tmp{ptmp};
    delete[] ptmp;
    return tmp;
}
void test_string() {
    std::string name{"bitofux"};
    std::string::iterator it{name.begin()};
    for (; it != name.end(); ++it) {
        std::cout << *it << "\n";
    }
}
void test_String() {
    String name{"bitofux"};
    String::iterator it{name.begin()};
    for (; it != name.end(); ++it) {
        std::cout << *it << "\n";
    }
}
int main() {
    test_string();
    test_String();

    return 0;
}
