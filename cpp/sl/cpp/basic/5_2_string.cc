/****************************************************
 * @file    5_2_string.cc
 * @brief   实现一个基本功能的string类
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
    ~String() {
        delete[] _data;
        _data = nullptr;
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

private:
    char* _data;
    friend std::ostream& operator<<(std::ostream& os, const String& src);
    friend String operator+(const String& lhs, const String& rhs);
};

std::ostream& operator<<(std::ostream& os, const String& src) { return (os << src._data); }
// 提供一个全局的运算符+的重载
String operator+(const String& lhs, const String& rhs) {
    /*效率低
    char* ptmp = new char[std::strlen(lhs._data) + std::strlen(rhs._data) + 1]{};
    std::strcat(ptmp, lhs._data);
    std::strcat(ptmp + lhs.length(), rhs._data);
    String tmp{ptmp};
    delete[] ptmp;
    return tmp;*/
    String tmp;
    delete[] tmp._data;
    tmp._data = new char[std::strlen(lhs._data) + std::strlen(rhs._data) + 1]{};
    std::strcat(tmp._data, lhs._data);
    std::strcat(tmp._data + lhs.length(), rhs._data);
    return tmp;
}
int main() {
    String name = "tofu";
    String name1{"bitofux"};
    String name2{name + name1};
    String name3{"add-" + name1};
    String name4{name1 + "add-"};
    std::cout << "name: " << name << "\nname1: " << name1 << "\nname2: " << name2
              << "\nname3: " << name3 << "\nname4: " << name4 << "\n";

    if (name2 > name1) {
        std::cout << name1 << " > " << name2 << "\n";
    } else {
        std::cout << name2 << " > " << name1 << "\n";
    }

    int len = name1.length();
    for (int i = 0; i < len; ++i) {
        std::cout << name1[i] << "\n";
    }

    const char* str = name1.c_str();
    std::cout << "str: " << str << "\n";
}
