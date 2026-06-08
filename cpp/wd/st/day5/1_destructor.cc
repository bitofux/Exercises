/*
 * PROJECT : EXERCISES
 * FILE    : 1_destructor.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-06-03
 * BRIEF   : 析构函数
 */
#include <cstring>
#include <iostream>

using std::cout;
using std::endl;

// 定义一个computer类
class Computer {
public:
    // 构造函数
    Computer(const char* brand, const double price)
        : m_brand{new char[strlen(brand) + 1]{}},
          m_price{price} {
        // 拷贝字符数据
        strcpy(m_brand, brand);
        cout << "Computer(const char*,double)\n";
    }
    // 析构函数释放持有的动态资源
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

// 无析构函数 -- 导致内存泄漏
void test() {
    Computer c1{"xiaomi", 2999};
    c1.show();
}

/*
 * 全局对象的析构时机 -- 发生在进程结束
 * 静态对象的析构时机 -- 发生在进程结束
 * 栈对象的析构时机   -- 栈对象所在的作用域结束
 * 堆对象的析构时机   -- delete
 */
// 全局对象
Computer c1{"apple", 12999};

// 局部静态对象
void test1() {
    static Computer c2{"huawei", 2000};
    c2.show();
}

// 堆对象
void test2() {
    Computer* ptr{new Computer{"apple", 3100}};
    delete ptr;
    ptr = nullptr;
}
int main() {
    cout << "main start\n";
    test2();
    cout << "main end\n";
    return 0;
}
