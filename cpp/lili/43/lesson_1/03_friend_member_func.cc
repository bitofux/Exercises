// 友元的第二种形式:友元之成员函数

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
    // 设置Line类的成员函数distance为Point类的友元成员函数
    friend double Line::distance(const Point& lhs, const Point& rhs);

private:
    int ix_;
    int iy_;
};

double Line::distance(const Point& lhs, const Point& rhs) {
    return std::hypot(lhs.ix_ - rhs.ix_, lhs.iy_ - rhs.iy_);
}
int main() {
    Point p1{1, 2}, p2{2, 3};
    std::cout << "distance: " << Line::distance(p1, p2) << std::endl;

    return 0;
}
