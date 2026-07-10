/*
 * PROJECT : EXERCISES
 * FILE    : 1.copy_constructor_inherit.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-07-10
 * BRIEF   : 继承体系下的拷贝构造与赋值运算符重载函数
 */
#include <iostream>

class father {
public:
    father(int f)
        : m_f{f} {
        std::cout << "father(int)" << std::endl;
    }

    // 拷贝构造函数
    father(const father& other)
        : m_f{other.m_f} {
        std::cout << "father(const father&)" << std::endl;
    }

    // 赋值运算符重载函数
    father& operator=(const father& other) {
        m_f = other.m_f;
        std::cout << "father::operator=(const father&)" << std::endl;
        return *this;
    }

public:
    int m_f;
};

class son : public father {
public:
    son(int s, int f)
        : m_s{s},
          father{f} {
        std::cout << "son(int)" << std::endl;
    }

    son(const son& other)
        : m_s{other.m_s},
          father(other) {
        std::cout << "son(const son& other)" << std::endl;
    }

    // 赋值运算符重载函数
    son& operator=(const son& other) {
        // 显式调用father类中的operator=函数
        father::operator=(other);
        m_s = other.m_s;
        std::cout << "son::operator=(const son&)" << std::endl;

        return *this;
    }

public:
    int m_s;
};

// 测试默认的拷贝构造函数是否调用father带一个参数的构造函数
void test() {
    son s{2, 3};

    son s1{s};
}

// 测试赋值运算符重载函数
void test1() {
    son s{2, 3};
    son s1{10, 20};

    s1 = s;

    std::cout << "m_f: " << s1.m_f << std::endl;
    std::cout << "m_s: " << s1.m_s << std::endl;
}

int main() {
    // test();

    test1();

    return 0;
}
