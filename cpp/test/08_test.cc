#include <cstring>
#include <iostream>
#include <string>
using std::cout;

class String {
public:
    String(const char* data) {
        // 判断data是否为nullptr;
        if (data == nullptr) {
            // 如果为nullptr,尽量别让_data也为nullptr
            // 这样在拷贝构造、赋值运算符重载函数中避免判断
            _data = new char[1]{};
            _data[0] = '\0';
        } else {
            // 先开辟内存,这是很容易犯错的点
            _data = new char[std::strlen(data) + 1]{};
            // 拷贝数据
            std::strcpy(_data, data);
        }
    }

    // 拷贝构造函数
    String(const String& other) {
        _data = new char[std::strlen(other._data) + 1]{};
        std::strcpy(_data, other._data);
    }

    // 赋值运算符重载函数
    String& operator=(const String& other) {
        if (this != &other) {
            delete[] _data;
            _data = new char[std::strlen(other._data) + 1]{};
            std::strcpy(_data, other._data);
        }

        return *this;
    }
    ~String() { delete[] _data; }
    void show() const { cout << "_data: " << _data << "\n"; }

private:
    char* _data;
};

int main() {
    String s1{"wangshuai"};
    s1.show();
    String s2{s1};
    s2.show();

    String s3{"bitofux"};
    s3.show();
    s3 = s1;
    s3.show();
}
