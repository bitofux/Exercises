/*
 * PROJECT : DAY6
 * FILE    : 6.static_member_function.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-06-08
 * BRIEF   : 静态成员函数 只属于类 且无this指针
 */
#include <iostream>
#include <string>
#include <utility>

using std::cout;
using std::endl;
using std::string;

class Human {
public:
    Human(string name, int age)
        : m_name{std::move(name)},
          m_age{age} {
        ++count;
        cout << "Human(string,int)" << endl;
    }

    // 普通成员函数
    void print() const { cout << "name: " << m_name << "\n" << "age: " << m_age << endl; }

    // 静态成员函数 无this指针
    // 不可直接访问普通数据成员，可访问静态数据成员
    static int get_static_member() {
        // 不可访问普通数据成员
        // m_name;
        // m_age;
        // print();

        // 但是可间接访问
        Human h1{"apple", 20};
        h1.m_name = "xiaomi";
        h1.m_age = 30;
        h1.print();
        return count;
    }

private:
    string m_name;
    int m_age;
    static int count;
};
int Human::count = 0;

int main() {
    Human h1{"huawei",40};

    cout << h1.get_static_member() << endl;
}
