/*
 * PROJECT : DAY11
 * FILE    : 4.1_singleton_autoreleased.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-06-27
 * BRIEF   : 1. 利用栈对象的生命周期自动释放单例对象
 */
#include <iostream>

class Singleton {
public:
    static Singleton* getInstance() {
        if (singleton_ == nullptr) {
            singleton_ = new Singleton{};
        }

        return singleton_;
    }

    static void destroy() {
        delete singleton_;
        singleton_ = nullptr;
    }

    // 禁用拷贝构造函数和赋值运算符重载函数
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

private:
    Singleton() = default;
    ~Singleton() = default;
    friend class AutoReleased;
    static Singleton* singleton_;
};
Singleton* Singleton::singleton_ = nullptr;

class AutoReleased {
public:
    AutoReleased(Singleton* singleton)
        : singleton_{singleton} {}
    ~AutoReleased() { Singleton::destroy(); }

private:
    Singleton* singleton_;
};

void test() { AutoReleased ar{Singleton::getInstance()}; }

int main() {
    test();

    return 0;
}
