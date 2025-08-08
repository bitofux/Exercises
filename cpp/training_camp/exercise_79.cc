// 定义一个结构体Point,包含两个成员变量x和y，类型为int
// 然后在main函数中，使用列表初始化定义一个Point对象
// 并初始化其成员变量
#include <iostream>

struct Point {
    Point(const int ix, const int iy)
        : ix_{ix},
          iy_{iy} {}
    void show() const { std::cout << "(" << ix_ << "," << iy_ << ")\n"; }
    int ix_;
    int iy_;
};

int main() {
    Point p1{10, 20};
    p1.show();
    return 0;
}
