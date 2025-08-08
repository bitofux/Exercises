// 定义一个类Counter，该类有一个静态成员变量用于记录
// 对象的数量。类中包含一个构造函数，该构造函数在每次创建
// 对象时递增静态成员变量的值。同时，类中包含一个静态成员
// 函数用于返回当前对象的总数
#include <iostream>

class Counter {
public:
    Counter() {
        count_++;
        std::cout << "Counter()\n";
    }
    static int get_count() { return Counter::count_; }

private:
    static int count_;
};

int Counter::count_ = 0;

int main() {
    Counter c1, c2, c3;

    std::cout << "当前对象总数: " << Counter::get_count() << '\n';

    return 0;
}
