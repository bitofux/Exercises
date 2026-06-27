/*
 * PROJECT : DAY11
 * FILE    : 4.3_singleton_autoreleased.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-06-27
 * BRIEF   : 利用atexit函数+destroy函数释放单例类
 */
#include <cstdlib>
#include <iostream>

class Singleton {
public:
    static Singleton* getInstance() {
        if (singleton_ == nullptr) {
            singleton_ = new Singleton{};
            atexit(&destroy);
        }

        return singleton_;
    }

    static void destroy() {
        std::cout << "destroy\n";
        delete singleton_;
        singleton_ = nullptr;
    }

    // 禁用拷贝构造函数和赋值运算符重载函数
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

private:
    Singleton() = default;
    ~Singleton() = default;
    static Singleton* singleton_;
};
Singleton* Singleton::singleton_ = nullptr;

int main() {
    Singleton* s = Singleton::getInstance();
    Singleton* s1 = Singleton::getInstance();

    std::cout << "s: " << s << "\n";
    std::cout << "s1: " << s1 << "\n";
    std::cout << "main end\n";
}
