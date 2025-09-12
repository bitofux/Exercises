#include <iostream>

using std::cout;

// 类模板 -- 实现一个通用的顺序栈
template <typename T>  // 模板类型参数
class SeqStack {
public:
    // 注意SeqStack现在不代表是一个类类型,它只是一个模板
    // 你需要带上类型参数一起才是一个完整类类型
    // 一个参数的构造函数
    SeqStack<T>(int size = 10)
        : _pstack{new T[size]{}},
          _top{-1},
          _size{size} {}
    // 析构函数
    ~SeqStack<T>() {
        delete[] _pstack;
        _pstack = nullptr;
    }
    // 拷贝构造函数
    SeqStack<T>(const SeqStack<T>& other){

}
    // 析构函数
private:
    T* _pstack;  // 指向顺序栈所在的内存
    int _top;
    int _size;
};
int main() {}
