/*
 * PROJECT : EXERCISES
 * FILE    : singleton_thread_safe.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-06-18
 * BRIEF   : 堆上创建的线程安全的单例模式
 */
#include <cstddef>
#include <iostream>
#include <mutex>

class Singleton {
public:
    static Singleton& getInstance() {
        std::call_once(flag_, []() { singleton_ptr_ = new Singleton{}; });
        return *singleton_ptr_;
    }

    // 禁用拷贝构造函数和赋值运算符函数
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

private:
    // 内部释放类
    class deleter {
    public:  // 析构函数如果是显式写的话，就必须是public的
             // 否则是无法创建栈上和存储在.data或者.bss段上的对象
        ~deleter() {
            delete singleton_ptr_;
            singleton_ptr_ = nullptr;
        }
    };
    Singleton() = default;
    ~Singleton() = default;
    static std::once_flag flag_;
    static deleter deleter_;
    static Singleton* singleton_ptr_;
};

Singleton* Singleton::singleton_ptr_ = nullptr;
Singleton::deleter Singleton::deleter_;
std::once_flag Singleton::flag_;

int main() {
    Singleton& ptr = Singleton::getInstance();
    Singleton& ptr1 = Singleton::getInstance();

    std::cout << (void*)&ptr << std::endl;
    std::cout << (void*)&ptr1 << std::endl;
}
