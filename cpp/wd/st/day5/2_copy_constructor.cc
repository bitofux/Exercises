/*
 * PROJECT : DAY5
 * FILE    : 2_copy_constructor.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-06-03
 * BRIEF   : 拷贝构造
 */
#include <cstring>
#include <iostream>
using namespace std;

// 无动态资源的类的拷贝构造 -- 无深拷贝和浅拷贝的概念
class Point {
public:
    Point(int x, int y)
        : m_x{x},
          m_y{y} {
        cout << "Point(int,int)" << endl;
    }
    Point(const Point& rhs)
        : m_x{rhs.m_x},
          m_y{rhs.m_y} {
        cout << "Point(const Point& rhs)" << endl;
    }
    void show() const { cout << m_x << " " << m_y << endl; }

private:
    int m_x;
    int m_y;
};

void test() {
    int a = 10;
    // 内置类型：使用已经定义且初始化的对象去定义初始化另外一个对象
    int b = a;
    // 推广到自定义类型
    Point p1{2, 3};
    // 使用已经定义且初始化的类对象去初始化一个新对象
    Point p2{p1};  // 调用类中的拷贝构造函数 若不定义，则编译器会自动生成一个
    p1.show();
    p2.show();
}

// 有动态资源的类 -- 有浅拷贝和深拷贝的概念
class Computer {
public:
    Computer(const char* brand, double price)
        : m_brand{new char[strlen(brand) + 1]{}},
          m_price{price} {
        strcpy(m_brand, brand);
        cout << "Computer(const char*,double)" << endl;
    }
    // 拷贝构造函数
    Computer(const Computer& rhs)
        : m_brand{new char[strlen(rhs.m_brand) + 1]{}},
          m_price{rhs.m_price} {
        strcpy(this->m_brand, rhs.m_brand);
        cout << "Computer(const Computer&)" << endl;
    }
    ~Computer() {
        cout << "~Computer()\n";
        delete[] m_brand;
        m_brand = nullptr;
    }
    void show() const { cout << "m_brand: " << m_brand << "\n" << "m_price: " << m_price << "\n"; }

private:
    char* m_brand;
    double m_price;
};

void test1() {
    Computer c1{"apple", 2999};
    // 使用已定义且初始化的对象c1去初始化另外一个新对象
    Computer c2{c1};
    c1.show();
}

/*
 * 拷贝构造函数的调用时机
 * 1. 用已经定义的对象初始化新对象
 * 2. 对象作为函数参数
 * 3. 对象作为函数返回值
 */

// 作为函数参数
void func(Computer c3) { c3.show(); }
void test2() { func(Computer{"huawei", 2111}); }

// 作为函数返回值 -- 注意返回值优化 RVO
Computer func3() { return Computer{"jixieshi", 3111}; }

void test3() {
    Computer c1 = func3();
    c1.show();
}
int main() { test3(); }
