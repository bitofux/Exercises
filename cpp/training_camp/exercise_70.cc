// 定义一个MyClass类，包含一个动态分配的整型数组作为成员
// 实现拷贝构造函数，确保深拷贝发生
#include <cstring>
#include <iostream>
#define SIZE 20
class MyClass {
public:
    MyClass(const int size)
        : size_{size},
          data_{new int[size]{}} {
        std::cout << "参数为const int的构造函数\n";
    }
    // 拷贝构造函数
    MyClass(const MyClass& other) {
        size_ = other.size_;
        data_ = new int[size_]{};
        std::copy(other.data_, other.data_ + other.size_, data_);
        std::cout << "拷贝构造函数\n";
    }
    // 析构函数
    ~MyClass() { std::cout << "析构函数\n"; }
    // 获取当前data_存储的地址值
    const int* get() const noexcept { return data_; }

private:
    int size_;
    int* data_;
};
int main() {
    MyClass arr_one{10};

    MyClass arr_two{arr_one};

    std::cout << "arr_one.data_: " << arr_one.get() << '\n';
    std::cout << "arr_two.data_: " << arr_two.get() << '\n';

    return 0;
}
