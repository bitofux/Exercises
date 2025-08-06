// 扩展MyClass类，实现移动构造函数
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
    // 析构函数
    ~MyClass() { std::cout << "析构函数\n"; }
    // 获取当前data_存储的地址值
    const int* get_data() const noexcept { return data_; }
    // 获取当前size_存储的值 (-1表示资源被窃取)
    int get_size() const noexcept { return size_; }

private:
    int size_;
    int* data_;
};
int main() {
    MyClass arr_one{10};

    std::cout << "before moving arr_one.data_: " << arr_one.get_data() << '\n';

    // 利用移动语义窃取arr_one的资源
    MyClass arr_two{std::move(arr_one)};
    std::cout << "after moving arr_one.data_: " << arr_one.get_data() << '\n';
    std::cout << "arr_two.data_: " << arr_two.get_data() << '\n';

    return 0;
}
