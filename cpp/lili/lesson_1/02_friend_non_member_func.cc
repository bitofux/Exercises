// 友元 -- 第一种形式 非成员函数(non member function)
#include <cmath>
#include <iostream>
class Point {
public:
    Point(const int ix = 0, const int iy = 0)
        : ix_{ix},
          iy_{iy} {
        std::cout << "Point(const int,const int)\n";
    }
    void print() const { std::cout << "(" << ix_ << ", " << iy_ << ")\n"; }
    ~Point() { std::cout << "~Point()\n"; }

private:
    friend double distance(const Point& p1, const Point& p2);

private:
    int ix_;
    int iy_;
};

// 非成员函数 -> 计算两个Point类对象的距离
// 不设置友元,在非成员函数内部访问不了私有
// 数据成员
double distance(const Point& p1, const Point& p2) {
    return std::hypot(p1.ix_ - p2.ix_, p1.iy_ - p2.iy_);
}

void test() {
    Point p1{2, 3}, p2{3, 4};
    std::cout << distance(p1, p2) << std::endl;
}
int main() {
    test();
    return 0;
}
