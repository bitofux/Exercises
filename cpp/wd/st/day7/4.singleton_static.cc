/*
 * PROJECT : DAY7
 * FILE    : singleton_static.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-06-12
 * BRIEF   : 单例模式 -- 静态对象
 */
#include <iostream>

using std::cout;
using std::endl;

class Singleton {
public:
    // 通过外部可访问的接口获取 不依赖对象状态 唯有静态成员函数
    // 返回引用的目的是返回的对象不是拷贝出去的对象，那就不是单例了
    static Singleton& GetInstance() {
        // 创建局部静态对象 C++11起，这种创建静态对象方式是线程安全的，当多个线程
        // 创建局部静态对象的时候，只允许一个线程通过创建。
        static Singleton singleton;

        return singleton;
    }

    // 禁用拷贝构造函数和赋值运算符重载函数
    Singleton(const Singleton&) = default;
    Singleton& operator=(const Singleton&) = default;

private:
    Singleton() = default;
    ~Singleton() = default;
};

int main() { return 0; }
