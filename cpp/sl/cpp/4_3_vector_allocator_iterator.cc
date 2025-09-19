/****************************************************
 * @file    4_3_vector_allocator_iterator.cc
 * @brief   为自定义的vector实现一个简单的迭代器
 * @author  bitofux
 * @date    2025-09-18
 ****************************************************/
// 实现一个带有自定义分配器的通用vector
#include <cstdlib>
#include <iostream>
#include <exception>
template <typename T>
class Allocator {
public:
    // 分配内存不构造对象
    T* allocate(int size) { return (T*)malloc(sizeof(T) * size); }
    // 构造对象
    void constructe(T* addr, const T& value) { new (addr) T{value}; }
    // 析构对象
    void destructe(T* addr) { (*addr).~T(); }
    // 释放内存
    void destory(T* addr) { free(addr); }
};
template <typename T, typename allocator = Allocator<T>>
class vector {
public:
    vector(int size, allocator alloc)
        : alloc_{alloc},
          first_{alloc_.allocate(size)},  // 只分配内存
          last_{first_},
          end_{first_ + size} {}
    ~vector() {
        // delete[] first_;
        // 只对有效元素进行析构
        for (int i = 0; i < size(); ++i) {
            alloc_.destructe(first_ + i);
        }
        first_ = last_ = end_ = nullptr;
    }
    vector(const vector<T>& other)
        : first_{alloc_.allocate(other.end_ - other.first_)},
          last_{first_ +
                (other.last_ - other.first_)},  // 编译器在运算符+上是没有int* + int *const的
          end_{first_ + (other.end_ - other.first_)} {
        int size = last_ - first_;
        for (int i = 0; i < size; ++i) {
            first_[i] = other.first_[i];
        }
    }
    vector<T>& operator=(const vector<T>& other) {
        if (this == &other) return *this;
        // 对有效元素进行析构
        for (int i = 0; i < size(); ++i) {
            alloc_.destructe(first_ + i);
        }
        // 释放内存
        alloc_.destory(first_);
        int cap = other.end_ - other.first_;
        // 分配内存
        first_ = alloc_.constructe(cap);
        int size = other.last_ - other.end_;
        for (int i = 0; i < size; ++i) {
            first_[i] = other.first_[i];
        }
        last_ = first_ + size;
        end_ = first_ + (other.end_ - other.first_);
        return *this;
    }

    void push_back(const T& element) {
        if (full()) {
            expand();
        }
        // 在last_处构造对象
        alloc_.constructe(last_, element);
        ++last_;
    }
    void pop_back() {
        if (empty()) {
            return;
        }
        // 析构对象
        alloc_.destructe(--last_);
    }
    T back() const { return *(last_ - 1); }

    bool full() const { return last_ == end_; }
    bool empty() const { return first_ == last_; }
    int size() const { return last_ - first_; }
    void show() const {
        T* ptmp = first_;
        for (; ptmp < last_; ++ptmp) {
            std::cout << *ptmp << " ";
        }
        std::cout << "\n";
    }
    // [] 运算符重载
    T& operator[](int index) {
        if (index < 0 || index >= size()) {
            throw "index out range";
        }
        return *(first_ + index);
    }

    // 简单的迭代器
    class iterator {
    public:
        iterator(T* ptr = nullptr)
            : ptr_{ptr} {}

        // 运算符!=
        bool operator!=(const iterator& src) { return ptr_ != src.ptr_; }
        // 运算符++ 前自增
        iterator& operator++() {
            ptr_++;
            return *this;
        }
        // 运算符*
        T& operator*() { return *ptr_; }

    private:
        T* ptr_;
    };

    iterator begin() { return iterator{first_}; }
    iterator end() { return iterator{last_}; }

private:
    void expand() {
        int cap = end_ - first_;
        int size = last_ - first_;
        // 分配内存
        T* tmp = alloc_.allocate(cap * 2);
        for (int i = 0; i < size; ++i) {
            tmp[i] = first_[i];
        }
        // 析构有效元素
        for (int i = 0; i < vector::size(); ++i) {
            alloc_.destructe(first_ + i);
        }
        // 释放内存
        alloc_.destory(first_);
        first_ = tmp;
        last_ = first_ + size;
        end_ = first_ + size * 2;
    }

private:
    allocator alloc_;
    T* first_;
    T* last_;
    T* end_;
};
void test_custom_type() {
    class test {
    public:
        test() { std::cout << "test()\n"; }
        test(const test& src) { std::cout << "test(const test&)\n"; }
        test& operator=(const test& src) {
            std::cout << "operator=(const test&)\n";
            return *this;
        }
        ~test() { std::cout << "~test()\n"; }
    };
    // 直接莫名其妙给了我10个test类型的对象,明明我只需要一部分空间而已
    // 还不需要实际的对象存在
    Allocator<test> alloc;
    vector<test> vec{10, alloc};
    std::cout << "----------------\n";
    test t1, t2, t3;
    // 由于之前直接有了10个test类型的对象,当我push_back的时候
    // 形式参数会触发拷贝构造,随后赋值的时候还要掉赋值运算符重载函数
    vec.push_back(t1);
    vec.push_back(t2);
    vec.push_back(t3);
    // 且我在pop_back的时候,只是简单的移动指针,并没有将这个对象真正的析构掉
    // 这样如果这个对象拥有动态资源的话,将会造成严重的泄露
    std::cout << "size: " << vec.size() << "\n";
    vec.pop_back();
    vec.pop_back();
    vec.pop_back();
    std::cout << "size: " << vec.size() << "\n";

    // 临时对象
    vec.push_back(test{});
    std::cout << "size: " << vec.size() << "\n";
}
void test_iterator() {
    Allocator<int> alloc;
    vector<int> vec{5, alloc};

    for (int i = 0; i < 5; ++i) {
        vec.push_back(i * 2);
    }

    auto it = vec.begin();
    for (; it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";
    for (auto& val : vec) {
        std::cout << val << "\n";
    }
}
int main() { test_iterator(); }
