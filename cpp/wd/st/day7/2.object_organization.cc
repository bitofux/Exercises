/*
 * PROJECT : EXERCISES
 * FILE    : 2.object_organization.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-06-09
 * BRIEF   : 对象组织 常对象、对象数组、堆对象、对象引用等的使用和内置类型一样的
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
    void show() const { cout << "name: " << m_name << "\nage: " << m_age << endl; }
    string m_name;
    int m_age;
};

// 常对象：对象中的数据成员不可被修改
void test() {
    const Human h1{"bitofux", 22};

    string s1 = "apple";
    // h1.m_name = s1; error
    // h1.m_age = 20; error
}

// 对象数组：数组的元素类型是类类型
void test2() {
    Human h1{"a", 22};
    Human h2{"b", 23};
    Human h3{"c", 24};

    Human arr[]{h1, h2, h3};  // 会调用拷贝构造函数

    for (const auto& h : arr) {
        h.show();
    }
}

// 堆对象
void test3() {
    Human* ptr{new Human{"a", 29}};
    ptr->show();

    delete ptr;
    ptr = nullptr;
}

// 对象引用
void test4() {
    Human h1{"bitofux", 30};
    Human& ref{h1};
    std::cout << "&ref: " << &ref << endl;
    std::cout << "&h1: " << &h1 << endl;
}

int main() {
    // test2();
    test4();
    return 0;
}
