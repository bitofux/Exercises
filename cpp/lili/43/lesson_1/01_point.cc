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
    int ix_;
    int iy_;
};

int main() {
    Point p1(2, 3);
    p1.print();

    return 0;
}
