/*
 * PROJECT : EXERCISES
 * FILE    : 1.const_function.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-06-09
 * BRIEF   : const成员函数 const成员函数可被对象和常对象访问 但是常对象不可访问普通成员函数
 */

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Human {
public:
    Human(string name, int age)
        : m_name{std::move(name)},
          m_age{age} {
        cout << "Human(string,int)" << endl;
    }

    // 定义一个普通的成员函数
    void show() { cout << "name: " << m_name << "\nm_age: " << m_age << endl; }

    // 定义一个const修饰的成员函数
    void print() const { cout << "name: " << m_name << "\nm_age: " << m_age << endl; }

    // const修饰的成员函数中，this指针是一个指向常量的常量指针，也就是说this不可以改变值
    // this指向的对象也不可修改数据成员，要记住const限制的是对象中的数据成员本身
    // 数据成员本身的值不可变，不要理解错了，比如指针数据成员，不要理解成是指针数据成员指向的内容不可变

private:
    string m_name;
    int m_age;
};

// 普通成员函数的调用
void test1() {
    // 使用普通对象调用普通成员函数
    Human h1{"bitofux", 20};
    h1.show();  // ok

    // 使用常对象调用普通成员函数
    const Human h2{"bitofux", 21};
    // h2.show(); error
}

// const修饰的成员函数的调用
void test2() {
    // 使用常对象调用const修饰的成员函数
    const Human h1{"bitofux", 222};
    h1.print();  // ok

    // 使用普通对象调用const修饰的成员函数
    Human h2{"bitofux", 23};
    h2.print();  // ok
}

int main() {
    test2();

    return 0;
}
