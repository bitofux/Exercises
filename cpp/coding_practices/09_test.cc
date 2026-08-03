#include <iostream>
using std::cout;

class Test {
public:
    Test()
        : _mf{10.2f} {}
    void test() { std::cout << "Test::test()\n"; }
    static double getCount() { return _count; }

    double getNumber() const { return _number; }
    double _number;
    const float _mf;
    static int _count;
};
int Test::_count = 10;

int main() {
    /*指向静态成员函数的指针*/
    double (*ptr_static_func)() = &Test::getCount;
    // 可以不依赖对象进行调用
    cout << ptr_static_func() << std::endl;

    /*指向普通成员函数的指针*/
    void (Test::*ptr_func)() = &Test::test;
    // 依赖对象访问: 普通成员函数是有this指针形参
    // 且普通函数需要访问数据成员的,是需要对象的
    // 1. 普通对象
    Test t1;
    (t1.*ptr_func)();
    // 2.对象指针
    Test* ptr{new Test};
    (ptr->*ptr_func)();
    // 3.常对象
    const Test t2{};
    //(t2.*ptr_func)();//不可使用常对象调用指向普通成员函数的函数指针

    /*指向常成员函数的指针*/
    double (Test::*ptr_const_func)() const = &Test::getNumber;
    // 1. 普通对象
    cout << (t1.*ptr_const_func)() << "\n";
    // 2.对象指针
    cout << (ptr->*ptr_const_func)() << "\n";
    // 3.常对象
    cout << (t2.*ptr_const_func)() << "\n";

    /*指向普通数据成员的指针*/
    double Test::* ptr_member = &Test::_number;
    // 1.普通对象
    t1.*ptr_member = 20;
    // 2.常对象
    //  t2.*ptr_member = 20;//error
    std::cout << t1._number << "\n";

    /*指向被const修饰的数据成员的指针,只能访问*/
    const float Test::* ptr_const_member = &Test::_mf;
    // 1.普通对象
    cout << "t1.*ptr_const_member: " << t1.*ptr_const_member << "\n";
    // 2.常对象
    cout << "t2.*ptr_const_member: " << t2.*ptr_const_member << "\n";

    /*指向静态数据成员的指针*/
    int* ptr_static = &Test::_count;
    *ptr_static = 30;
    std::cout << "_count: " << Test::_count << "\n";

    return 0;
}
