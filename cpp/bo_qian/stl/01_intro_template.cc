// 简要介绍函数模板和类模板
#include <iostream>
#include <cassert>

// 函数模板
// 可以从参数中推断数据类型，因此可以不必明确编译器
// 数据类型是什么
template <typename T>
T squre(T x) {
    return x * x;
}

// int squre(int x) { return x * x; }
// double squre(double x) { return x * x; }

// 类模板
// 对于类模板你必须明确告诉编译器你正在使用的数据类型
//
template <typename T>
class Bitofux {
    T arr_[1000];
    int size_;

public:
    Bitofux()
        : size_{0} {}
    void push(T x) {
        arr_[size_] = x;
        size_++;
    }
    T get(int i) const {
        assert(i >= 0 && i < 1000);
        return arr_[i];
    }
    int getSize() const { return size_; }
    void print() const {
        for (int i = 0; i < size_; i++) {
            std::cout << arr_[i] << '\n';
        }
    }
    // 运算符* 重载
    // 记住Bitofux是一个模板类
    // 它的类型是Bitofux<T>
    Bitofux<T> operator*(const Bitofux<T>& other) {
        Bitofux<T> vec;
        for (int i = 0; i < size_; i++) {
            vec.push(this->arr_[i] * other.arr_[i]);
        }
        return vec;
    }
};

int main() {
    Bitofux<int> bit{};
    bit.push(2);
    bit.push(5);
    bit.push(8);
    bit.push(9);
    // bit.print();

    bit = squre(bit);
    bit.print();
    return 0;
}
