#include <iostream>

using std::cout;

// 模板类 -- 实现一个通用类型的顺序栈
template <typename T>
class SeqStack {
public:
    // 构造函数是与类名一样的，但是此时SeqStack不是一个完整的类名,它现在是一个
    // 类模板名,需要带上类型参数才是一个完整的类类型
    SeqStack(int size = 10)
        : _pstack{new T[size]{}},
          _top{-1},
          _size{size} {}
    // 析构函数
    ~SeqStack() {
        delete[] _pstack;
        _pstack = nullptr;
    }
    // 拷贝构造函数
    SeqStack(const SeqStack<T>& other)
        : _pstack{new T[other._size]{}},
          _top{other._top},
          _size{other._size} {
        for (int i = 0; i <= _top; ++i) {
            _pstack[i] = other._pstack[i];
        }
    }
    // 赋值运算符重载函数
    SeqStack<T>& operator=(const SeqStack<T>& other) {
        if (this != &other) {
            delete[] _pstack;
            _pstack = new T[other._size]{};
            for (int i = 0; i <= other._top; ++i) {
                _pstack[i] = other._pstack[i];
            }
            _size = other._size;
            _top = other._top;
        }
        return *this;
    }
    // 元素入栈
    void push(T element) {
        // 判断是否栈满
        if (full()) {
            expand();
        }
        _pstack[++_top] = element;
    }
    // 元素出栈
    void pop() {
        // 判断是否栈空
        if (empty()) {
            throw "SeqStack is empty";
        }
        --_top;
    }
    // 获取栈顶元素 类内声明
    T top() const;
    // 判断是否栈满
    bool full() const { return _top == _size - 1; }
    // 判断是否栈空
    bool empty() const { return _top == -1; }
    // 打印顺序栈元素
    void show() const {
        for (int i = _top; i >= 0; --i) {
            cout << _pstack[i] << "\n";
            cout << "--\n";
        }
    }

private:
    T* _pstack;
    int _top;
    int _size;
    // 二倍扩容
    void expand() {
        T* ptmp = new T[_size * 2]{};
        for (int i = 0; i <= _top; ++i) {
            ptmp[i] = _pstack[i];
        }
        delete[] _pstack;
        _pstack = ptmp;
        _size *= 2;
    }
};
// 类外定义 -- 需带上模板类型参数 SeqStack<T>
// 才是依赖模板参数的类类型,模板SeqStack<T>::top
// 告诉编译器这是模板SeqStack在参数T下的成员函数实现
// 指明它属于哪个模板实例化
template <typename T>
T SeqStack<T>::top() const {
    return _pstack[_top];
}

void test_int() {
    SeqStack<int> ss;
    ss.push(10);
    ss.push(20);
    ss.push(30);
    ss.push(40);
    ss.pop();
    ss.pop();
    ss.pop();
    ss.show();
    // cout << "top: " << ss.top() << "\n";
    SeqStack<int> ss1 = ss;
    ss1.show();
    cout << "-----------\n";

    SeqStack<int> ss2;
    ss2.push(1);
    ss2.push(2);
    ss2.show();
    cout << "----------\n";
    ss1 = ss2;
    ss1.show();
}
void test_double() {
    SeqStack<double> ss;
    ss.push(10.10);
    ss.push(20.20);
    ss.push(30.30);
    ss.push(40.40);
    ss.pop();
    ss.pop();
    ss.pop();
    ss.show();
    cout << "top: " << ss.top() << "\n";
}
int main() {
    test_int();
    test_double();
}
