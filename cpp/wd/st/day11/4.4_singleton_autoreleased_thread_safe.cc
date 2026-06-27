/*
 * PROJECT : DAY11
 * FILE    : 4.4_singleton_autoreleased_thread_safe.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-06-27
 * BRIEF   : 线程安全单例类 利用atexit
 */
#include <pthread.h>
#include <cstdlib>
#include <iostream>

class Singleton {
public:
    static Singleton* getInstance() {
        pthread_once(&once_flag, &init);
        return singleton_;
    }

    // 禁用拷贝构造函数和赋值运算符重载函数
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

private:
    static void init() {
        std::cout << "init\n";
        singleton_ = new Singleton{};
        atexit(destroy);
    }
    static void destroy() {
        std::cout << "destroy\n";
        delete singleton_;
        singleton_ = nullptr;
    }
    Singleton() = default;
    ~Singleton() = default;
    static pthread_once_t once_flag;
    static Singleton* singleton_;
};
Singleton* Singleton::singleton_ = nullptr;
pthread_once_t Singleton::once_flag;

int main() {
    Singleton* s = Singleton::getInstance();
    Singleton* s1 = Singleton::getInstance();

    std::cout << "s: " << s << "\n";
    std::cout << "s1: " << s1 << "\n";
    std::cout << "main end\n";
}
