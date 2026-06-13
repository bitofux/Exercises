/*
 * PROJECT : DAY7
 * FILE    : 5.singleton_dynamic.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-06-12
 * BRIEF   : 单例模式 创建在堆上
 */

// 1. 错误版
#include <iostream>
#include <mutex>

class Singleton {
public:
    // 提供外部接口使得使用静态数据成员接收堆对象地址
    static Singleton* GetInstance() {
        s_ptr = new Singleton{};

        return s_ptr;
    }

private:
    Singleton() = default;
    static Singleton* s_ptr;
};
// 初始化静态数据成员
Singleton* Singleton::s_ptr = nullptr;

/*
 * 1.
 * 第一个问题：外部拿到地址之后，由于类内没有不允许拷贝构造，那么外部可通过解引用去拷贝新的对象，不符合单例特征
 * 2.
 * 当当前进程结束的时候，被销毁的只是这个静态数据成员s_ptr，但是堆上的内存还没被释放，造成资源泄露
 * 3.
 * 每次调用GetInstance函数都会有new一次，需要判断条件
 */
/*
 * 1. delete拷贝构造和赋值运算符函数
 * 2. 创建一个内部类，权限设置为private，并创建一个此类的静态对象，让其自动调用析构函数并释放s_ptr
 */
// 2. 修订版
class SingletonModify {
public:
    static SingletonModify* GetInstance() {
        if (s_ptr_ == nullptr) {
            s_ptr_ = new SingletonModify{};
        }

        return s_ptr_;
    }

    SingletonModify(const SingletonModify&) = delete;
    SingletonModify& operator=(const SingletonModify&) = delete;

private:
    // 创建一个内部类
    class deleter {
    public:
        ~deleter() {
            std::cout << "~deleter()\n";

            delete s_ptr_;
            s_ptr_ = nullptr;
        }
    };
    static deleter deleter_;
    SingletonModify() = default;
    ~SingletonModify() = default;
    static SingletonModify* s_ptr_;
};

SingletonModify* SingletonModify::s_ptr_ = nullptr;
SingletonModify::deleter SingletonModify::deleter_;

// 测试修订版
void test() {
    using sm = SingletonModify;
    sm* ptr = sm::GetInstance();
    sm* ptr1 = sm::GetInstance();

    std::cout << ptr << std::endl;
    std::cout << ptr1 << std::endl;
}

int main() {
    test();

    return 0;
}
