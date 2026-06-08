/*
 * PROJECT : DAY6
 * FILE    : static_member.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-06-08
 * BRIEF   : 静态数据成员 与全局和静态、局部静态对象一样存储在.data或.bss
 *           它是一个类类型所有对象共享的数据成员，且只属于类本身
 */
#include <iostream>
#include <ostream>
#include <string>
#include <utility>

using std::cout;
using std::endl;
using std::string;

class Student {
public:
    Student(int id, string name)
        : m_id{id},
          m_name{std::move(name)} {
        cout << "Student(int,string)" << endl;
    }
    friend std::ostream& operator<<(std::ostream& os, const Student& s);

private:
    int m_id;
    string m_name;
    static int m_class;
};
// 类外定义静态数据成员
int Student::m_class = 1;

std::ostream& operator<<(std::ostream& os, const Student& s) {
    os << s.m_id << " " << s.m_name << " " << Student::m_class;
    return os;
}
int main() {
    Student s1{10, "bitofux"};
    Student s2{20, "wangshuai"};
    Student s3{30, "xiaxia"};

    cout << s1 << "\n" << s2 << "\n" << s3;

    return 0;
}
