//[]运算符重载 -- 成员函数方式
#include <cstddef>
#include <iostream>

// int arr[10] {1,2,3};
// arr.operator[](size_t idx)

class CharArray {
public:
    CharArray(const size_t size)
        : size_{size},
          data_{new char[size_]{}} {
        std::cout << "CharArray(const int)\n";
    }
    size_t size() const { return size_; }
    // 重载[]运算符，由于data_指向的是一个堆内存
    // 那么当一个CharArray对象使用[]这个运算符时
    // 这个堆内存一定是还是有效的，因为此时CharArray
    // 对象还未调用析构函数,因此此运算符重载的返回值
    // 类型可以是左值引用
    char& operator[](size_t idx) { return data_[idx]; }
    ~CharArray() {
        delete[] data_;
        data_ = nullptr;
        std::cout << "~CharArray()\n";
    }

private:
    size_t size_;
    char* data_;
};

void test() {
    CharArray arr{5};

    // 想要通过[]运算符的方式为CharArray中的数据成员
    // data_的访问和修改，需要为这个类重载[]运算符
    for (size_t i = 0; i < arr.size(); i++) {
        arr[i] = 'a' + i;
    }

    for (size_t i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << '\n';
    }
}

int main() {
    test();

    return 0;
}
