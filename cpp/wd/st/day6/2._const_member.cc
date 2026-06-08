/*
 * PROJECT : DAY6
 * FILE    : 2._const_member.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-06-08
 * BRIEF   : 常量数据成员 -- 构造对象时必须初始化，若有多个构造函数则都要进行初始化
 *           C++11中可以声明即初始化
 */
#include <iostream>

using std::cout;
using std::endl;

class Data {
public:
    // 无参构造函数
    Data()
        : m_data2{10} {  // 也要进行初始化
    }
    // 多参构造函数
    Data(int data1, int data2)
        : m_data1{data1},
          m_data2{data2} {
        cout << "Data(int,int)" << endl;
    }
    void print() const {
        cout << "m_data1: " << m_data1 << "\nm_data2: " << m_data2 << "\nm_data3: " << m_data3
             << "\n";
    }

private:
    int m_data1;
    const int m_data2;
    // C++11之后，也可声明即初始化，感觉大概原理就是编译器帮你在所有构造函数中添加了一个初始化操作
    const int m_data3 = 200;
};

int main() {
    Data d1{1, 2};
    d1.print();
}
