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

int main() {
    using vector = vector<int>;
    vector vec{6};
    for (int i = 0; i < 6; ++i) {
        vec.push_back(i * 2);
    }

    vec.show();

    vector v1{vec};
    v1.show();
    v1.pop_back();
    vec = v1;
    vec.show();
    return 0;
}
