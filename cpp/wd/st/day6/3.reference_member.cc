/*
 * PROJECT : DAY6
 * FILE    : 3.reference_member.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-06-08
 * BRIEF   : 引用数据成员: 引用数据成员初始化的对象的生命周期一定大于或等于此引用数据成员
 */
#include <iostream>

using std::cout;
using std::endl;

class Data {
public:
    Data(int num, int& ref)
        : m_num{num},
          m_ref{ref} {
        cout << "Data(int,int&)" << "\n";
    }

    void print() const { cout << "m_num: " << this->m_num << "\nm_ref: " << this->m_ref << endl; }

private:
    int m_num;
    int& m_ref;
};

void test() {
    int num = 20;

    Data d1{10, num};

    // d1中的引用数据成员与所引用的对象num的生命周期是相等的 这是没问题的
    // 不要引用一个生命周期比自己小的对象
    d1.print();
}

int main() {
    test();

    return 0;
}
