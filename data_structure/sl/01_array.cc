#include <cstdlib>
#include <ctime>
#include <iostream>

// Array:假设元素的类型是int
class Array {
public:
    // 构造并初始化一个顺序表,初始容量为10
    Array(int size = 10)
        : cap_{size},
          cur_{0},
          ptr_{new int[cap_]{}} {}

    // 不需要拷贝构造和赋值运算符函数
    Array(const Array& other) = delete;
    Array& operator=(const Array& other) = delete;

    // 销毁顺序表
    ~Array() {
        delete[] ptr_;
        ptr_ = nullptr;
    }

public:
    // 末尾增加元素
    void push_back(int val) {
        // 判断顺序表是否已满
        if (cap_ == cur_) {
            // 扩容
            expand(cap_ * 2);
        }

        // 末尾增加元素
        ptr_[cur_] = val;
        // 将顺序表中的有效个数+1
        ++cur_;
    }
    // 末尾删除元素
    void pop_back() {
        // 判断顺序表是否为空
        if (cur_ == 0) {
            return;
        }
        --cur_;
    }
    // 按位置增加元素(0-based 下标添加)
    void insert(int pos, int val) {
        // 先判断pos是否合法(pos可以是cur_,在顺序表末尾添加)
        if (pos < 0 || pos > cur_) {
            return;
        }

        // 在判断顺序表是否已满
        if (cur_ == cap_) {
            // 扩容
            expand(2 * cap_);
        }

        // 移动元素
        for (int i = cur_ - 1; i >= pos; i--) {
            ptr_[i + 1] = ptr_[i];
        }

        // 添加元素
        ptr_[pos] = val;

        // 更新顺序表数据成员的数据
        ++cur_;
    }
    // 按位置删除元素(0-based下标删除)
    void remove(int pos) {
        // 判断pos是否合法(cur_此时代表的是顺序表末尾位置,无元素不可删除)
        if (pos < 0 || pos >= cur_) {
            return;
        }

        // 判断顺序表是否为空
        if (cur_ == 0) {
            return;
        }

        // 移动元素(覆盖pos位置上的元素)
        for (int i = pos + 1; i < cur_; i++) {
            ptr_[i - 1] = ptr_[i];
        }

        // 更新顺序表中数据成员的数据
        --cur_;
    }
    // 元素查询返回下标
    int find(int val) const {
        if (cur_ == 0) {
            return -1;
        }

        for (int i = 0; i < cur_; i++) {
            if (ptr_[i] == val) {
                return i;
            }
        }

        return -1;
    }
    // 打印顺序表中的数据
    void show() const {
        if (cur_ == 0) {
            std::cout << "(empty)\n";
            return;
        }

        for (int i = 0; i < cur_; i++) {
            std::cout << ptr_[i] << " ";
        }
        std::cout << "\n";
    }

private:
    // 扩容
    void expand(int size) {
        // 申请size个元素大小的堆内存
        int* p = new int[size];
        // 将原来的堆内存数据拷贝一份到新的堆内存(注意深浅拷贝)
        for (int i = 0; i < cur_; i++) {
            p[i] = ptr_[i];
        }
        // 释放原来的堆内存
        delete[] ptr_;

        // 更新顺序表中数据成员的数据
        ptr_ = p;
        cap_ = size;
    }

private:
    int cap_;   // 顺序表中的容量
    int cur_;   // 顺序表中有效元素的个数
    int* ptr_;  // 指向可扩容的顺序表内存
};

int main() {
    Array arr{5};

    srand(time(0));

    for (int i = 0; i < 5; i++) {
        arr.push_back(rand() % 100);
    }
    arr.show();

    arr.insert(0, 20);
    arr.show();
    arr.insert(2, 30);
    arr.show();

    arr.insert(7, 111);
    arr.show();

    arr.remove(7);
    arr.show();

    arr.remove(0);
    arr.show();

    int pos = arr.find(30);
    if (pos != -1) {
        arr.remove(pos);
    }

    arr.show();
}
