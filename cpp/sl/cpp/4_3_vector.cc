// 实现一个简单的通用vector
#include <iostream>

template <typename T>
class vector {
public:
    vector(int size)
        : first_{new T[size]},
          last_{first_},
          end_{first_ + size} {}
    ~vector() {
        delete[] first_;
        first_ = last_ = end_ = nullptr;
    }
    vector(const vector<T>& other)
        : first_{new T[other.end_ - other.first_]},
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
        delete[] first_;
        int size = other.last_ - other.first_;
        first_ = new T[other.end_ - other.first_];
        for (int i = 0; i < size; ++i) {
            first_[i] = other.first_[i];
        }
        last_ = first_ + size;
        end_ = first_ + (other.end_ - other.first_);
        return *this;
    }

    void push_back(T element) {
        if (full()) {
            expand();
        }
        *last_ = element;
        ++last_;
    }
    void pop_back() {
        if (empty()) {
            return;
        }
        --last_;
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

private:
    void expand() {
        int size = end_ - first_;
        T* ptmp = new T[size * 2];
        for (int i = 0; i < size; ++i) {
            ptmp[i] = first_[i];
        }
        delete[] first_;
        first_ = ptmp;
        last_ = first_ + size;
        end_ = first_ + size * 2;
    }

private:
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
    vector<test> vec{10};
    std::cout << "----------------\n";
    test t1, t2, t3;
    // 由于之前直接有了10个test类型的对象,当我push_back的时候
    // 形式参数会触发拷贝构造,随后赋值的时候还要掉赋值运算符重载函数
    vec.push_back(t1);
    vec.push_back(t2);
    vec.push_back(t3);
    // 且我在pop_back的时候,只是简单的移动指针,并没有将这个对象真正的析构掉
    // 这样如果这个对象拥有动态资源的话,将会造成严重的泄露
    vec.pop_back();
    vec.pop_back();
    vec.pop_back();
}
int main() {
    test_custom_type();
    // using vector = vector<int>;
    // vector vec{6};
    // for (int i = 0; i < 6; ++i) {
    //     vec.push_back(i * 2);
    // }
    //
    // vec.show();
    //
    // vector v1{vec};
    // v1.show();
    // v1.pop_back();
    // vec = v1;
    // vec.show();
    return 0;
}
