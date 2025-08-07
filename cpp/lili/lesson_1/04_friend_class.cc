// 友元的第三种形式：友元类
// 当A类中的大多数成员函数都需要用到B类的私有成员时
// 可以在B类中设置A为自己的友元类

#include <cmath>
#include <iostream>

// 前向声明类
class Point;
// 计算距离的类
class Line {
public:
    Line() { std::cout << "Line()\n"; }
    // 前向声明的Point类型是不完整的，因此无法在当前函数使用
    // 因此需要在Point类类型定义完整之后补充定义
    static double distance(const Point& lhs, const Point& rhs);
    static void set_point(Point& lhs, int ix, int iy);
};
class Point {
public:
    Point(const int ix = 0, const int iy = 0)
        : ix_{ix},
          iy_{iy} {
        std::cout << "Point(const int,const int)\n";
    }
    void print() const { std::cout << "(" << ix_ << "," << iy_ << ")\n"; }
    ~Point() { std::cout << "~Point()\n"; }

private:
    // 设置Line为自己的友元类
    // Line可访问Point的私有成员
    friend class Line;

private:
    int ix_;
    int iy_;
};

double Line::distance(const Point& lhs, const Point& rhs) {
    return std::hypot(lhs.ix_ - rhs.ix_, lhs.iy_ - rhs.iy_);
}
void Line::set_point(Point& lhs, int ix, int iy) {
    lhs.ix_ = ix;
    lhs.iy_ = iy;
}
int main() {
    Point p1{1, 2}, p2{2, 3};
    Line::set_point(p1, 4, 3);
    p1.print();
    return 0;
}
