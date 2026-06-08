/*
 * PROJECT : EXERCISES
 * FILE    : 1.operator_assign.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-06-08
 * BRIEF   : 赋值运算符重载函数
 */
#include <cstring>
#include <iostream>

using std::cout;
using std::endl;

class Point {
public:
    Point(int x, int y)
        : m_x{x},
          m_y{y} {
        cout << "Point(int ,int )" << endl;
    }

    // 拷贝构造函数
    // 显式若不进行初始化或者赋值，编译器不再帮你进行赋值或者初始化，而是初始化为0
    Point(const Point& rhs)
        : m_x{rhs.m_x},
          m_y{rhs.m_y} {
        cout << "Point(const Point&)" << endl;
    }

    // 赋值运算符函数(使用一个已经定义的对象赋值另外一个已经定义的对象)
    // 若显式写出赋值运算符函数，若函数内部不进行任何赋值操作，那么编译器
    // 不会帮你完成赋值，被赋值对象的数据成员还是原来的值
    Point& operator=(const Point& rhs) {
        // 防止自赋值
        if (this != &rhs) {
            this->m_x = rhs.m_x;
            this->m_y = rhs.m_y;
        }
        return *this;
    }

    // 输出Point类型对象的数据成员的值
    void print() const { cout << "m_x: " << this->m_x << "\nm_y: " << this->m_y << endl; }

private:
    int m_x;
    int m_y;
};

// 拷贝构造函数测试，Point类没有动态资源
// 没有深浅拷贝一说
void test1() {
    Point p1{1, 2};
    Point p2{p1};

    p2.print();
}

// 赋值运算符重载函数，无动态资源
// 无深浅拷贝一说
void test2() {
    Point p1{1, 2};
    Point p2{2, 2};

    p2 = p1;  // p2.operator=(p1);
    p2.print();
}

// 赋值运算符的浅拷贝
class Computer {
public:
    Computer(const char* brand, double price)
        : m_brand{new char[strlen(brand) + 1]{}},
          m_price{price} {
        cout << "Computer(const char* double)" << endl;
        strcpy(m_brand, brand);
    }

    // 深拷贝的拷贝构造函数
    Computer(const Computer& rhs)
        : m_brand{new char[strlen(rhs.m_brand) + 1]{}},
          m_price{rhs.m_price} {
        cout << "Computer(const Computer&)" << endl;
    }

    // 深拷贝的赋值运算符重载函数
    Computer& operator=(const Computer& rhs) {
        cout << "operator=(const Computer&)" << endl;
        // 避免自赋值
        if (this != &rhs) {
            // 依据rhs.m_brand申请新的内存空间
            // 拷贝数据
            char* tmp = new char[strlen(rhs.m_brand) + 1]{};
            strcpy(tmp, rhs.m_brand);

            // 释放当前this指针指向对象的m_brand指向的堆空间
            delete[] this->m_brand;

            // 指向新的堆内存空间
            this->m_brand = tmp;
            this->m_price = rhs.m_price;
        }

        return *this;
    }

    // 析构函数
    ~Computer() {
        delete[] m_brand;
        m_brand = nullptr;
    }

    // 返回m_brand的地址
    const char* ptr() const { return this->m_brand; }

    // 输出数据成员
    void print() const {
        cout << "m_brand: " << this->m_brand << "\nm_price: " << this->m_price << endl;
    }

private:
    char* m_brand;
    double m_price;
};

// 测试编译器默认生成的赋值运算符重载函数的浅拷贝
void test3() {
    Computer c1{"xiaomi", 2999};
    Computer c2{"apple", 5999};

    c2 = c1;

    // 结果一样 发生浅拷贝，若析构函数有释放资源动作
    // 会造成double free导致程序崩溃
    // 因此需要深拷贝
    cout << "c2.m_brand: " << static_cast<void*>(const_cast<char*>(c2.ptr())) << "\n";
    cout << "c1.m_brand: " << static_cast<void*>(const_cast<char*>(c1.ptr())) << "\n";

    c1.print();
    c2.print();
}

int main() { test3(); }
