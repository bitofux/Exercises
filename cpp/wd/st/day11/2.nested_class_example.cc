/*
 * PROJECT : EXERCISES
 * FILE    : 2.nested_class_example.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-06-27
 * BRIEF   : 嵌套类的应用
 */
#include <iostream>
#include <ostream>

using std::cout;
using std::endl;
using std::ostream;

class Line {
public:
    Line(int x1, int y1, int x2, int y2)
        : p1_{x1, y1},
          p2_{x2, y2} {
        cout << "Line(int,int,int,int)\n";
    }

private:
    class point {
    public:
        point(int x, int y)
            : x_{x},
              y_{y} {
            cout << "point(int, int)" << endl;
        }

    private:
        int x_;
        int y_;
        friend ostream& operator<<(ostream& os, const Line::point& line);
    };
    friend ostream& operator<<(ostream& os, const Line& line);
    friend ostream& operator<<(ostream& os, const Line::point& p);
    point p1_;
    point p2_;
};

ostream& operator<<(ostream& os, const Line::point& p) {
    os << "(" << p.x_ << "," << p.y_ << ")";
    return os;
}
ostream& operator<<(ostream& os, const Line& line) {
    os << "(" << line.p1_ << "," << line.p2_ << ")";
    return os;
}

void test() {
    Line l{1, 2, 3, 4};

    std::cout << l << std::endl;
}

int main() {
    test();

    return 0;
}
