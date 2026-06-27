/*
 * PROJECT : DAY11
 * FILE    : 4.2_singleton_autoreleased.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-06-27
 * BRIEF   : 2. 利用内部类+静态内部类对象释放单例类
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

    // static void destroy() {
    //     delete singleton_;
    //     singleton_ = nullptr;
    // }

    // 禁用拷贝构造函数和赋值运算符重载函数
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

private:
    struct deleter {
        ~deleter() {
            delete singleton_;
            singleton_ = nullptr;
        }
    };
    Singleton() = default;
    ~Singleton() = default;
    friend class AutoReleased;
    static Singleton* singleton_;
    static deleter deleter_;
};
Singleton* Singleton::singleton_ = nullptr;
Singleton::deleter Singleton::deleter_;

int main() {
    Singleton* s = Singleton::getInstance();
    Singleton* s1 = Singleton::getInstance();

    std::cout << "s: " << s << "\n";
    std::cout << "s1: " << s1 << "\n";

    return 0;
}
