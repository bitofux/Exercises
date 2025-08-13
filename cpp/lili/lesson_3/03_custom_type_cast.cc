/****************************************************
 * @file    03_custom_type_cast.cc
 * @brief   当前自定义类型是Point
 *          从其他类型到Point的隐式转换需要依赖构造函数
 *          从Point到其他类型(内置)需要重载类型函数
 * @author  bitofux
 * @date    2025-08-13
 ****************************************************/
#include <iostream>

class Point;
class Complex {
public:
    Complex(double real, double dimage)
        : real_{real},
          dimage_{dimage} {
        std::cout << "Complex(double,double)\n";
    }

public:
    // 友元类
    friend Point;

private:
    double real_;
    double dimage_;
};

class Point {
public:
    Point(int ix, int iy)
        : ix_{ix},
          iy_{iy} {
        std::cout << "Point(int,int)\n";
    }
    // 从Complex类型转换Point
    Point(const Complex& other)
        : ix_{static_cast<int>(other.real_)},
          iy_{static_cast<int>(other.dimage_)} {
        std::cout << "Point(const Complex&)\n";
    }
    //从Point到其他类型 比如bool
    explicit operator bool() const {
        if (ix_ == 0 && iy_ == 0) {
            return false;
        }

        return true;
    }
    void print() const { std::cout << "(" << ix_ << "," << iy_ << ")\n"; }

private:
    int ix_;
    int iy_;
};
void test() {
    Complex c1{2, 3};
    //p1.Point(&p1,const Complex&)
    Point p1{c1};  // Complex隐式转换到Point
    p1.print();
}

void test1() {
    Point p1 {2,3};
    if (p1) {
        std::cout << "is true!\n";
    }
}
int main() {
    test1();

    return 0;
}
