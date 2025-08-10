// 定义一个结构体Point,包含两个成员变量x和y，类型为int
// 然后在main函数中，使用列表初始化定义一个Point对象
// 并初始化其成员变量
#include <iostream>

struct Point {
    Point(const int ix, const int iy)
        : ix{ix},
          iy{iy} {}
    void show() const { std::cout << "(" << ix << "," << iy << ")\n"; }
    int ix;
    int iy;
};

int main() {
    Point p1{10, 20};
    p1.show();
    return 0;
}
