// 为MyClass类实现赋值运算符重载函数
#include <algorithm>
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
    // 移动构造函数
    MyClass(MyClass&& other)
        : size_{other.size_},
          data_{other.data_} {
        other.size_ = -1;
        other.data_ = nullptr;
        std::cout << "移动构造函数\n";
    }
    // 赋值运算符重载函数
    MyClass& operator=(const MyClass& other) {
        // 避免自赋值
        if (this != &other) {
            // 若this->data_不为nullptr
            if (data_) {
                // 释放当前对象data_持有的资源
                delete[] data_;
            }
            size_ = other.size_;
            data_ = new int[size_]{};
            std::copy(other.data_, other.data_ + other.size_, data_);
        }
        std::cout << "赋值运算符重载函数\n";
        return *this;
    }
    // 析构函数
    ~MyClass() { std::cout << "析构函数\n"; }
    // 获取当前data_存储的地址值
    const int* get_data() const noexcept { return data_; }
    // 获取当前size_存储的值 (-1表示资源被窃取)
    int get_size() const noexcept { return size_; }

    // 初始化整型数组
    void init_data(int base) noexcept {
        for (int i = 0; i < size_; i++) {
            data_[i] = i + base;
        }
    }

    // 输出数组中的元素值
    void show() const noexcept {
        for (int i = 0; i < size_; i++) {
            std::cout << "data_[" << i << "]: " << data_[i] << ' ';
        }
        std::cout << std::endl;
    }

private:
    int size_;
    int* data_;
};
int main() {
    // arr_one
    MyClass arr_one{2};
    arr_one.init_data(2);
    arr_one.show();

    // arr_two
    MyClass arr_two{3};
    arr_two.init_data(10);
    arr_two.show();

    // 将arr_two赋值给arr_one
    arr_one = arr_two;
    arr_one.show();

    return 0;
}
