/****************************************************
 * @file    02_thread_detach.cc
 * @brief   线程对象的管理:
 *              一个线程对象是管理着一个线程,但是它并不是
 *              对线程有所有权的.
 *              意味着当一个线程还在运行,但是线程对象却
 *              被销毁了,会带来一些错误行为.
 *          1.线程分离,detach也会带来问题,就是当主线程
 *            结束之后,如果子线程中还在访问进程内的共享
 *            资源,就会产生错误行为.
 *          2.使用全局变量通知子线程可以退出,建议使用原子
 *            类型的变量
 * @author  bitofux
 * @date    2025-08-23
 ****************************************************/
#include <iostream>
#include <chrono>
#include <thread>
#include <atomic>

std::atomic<bool> notice{false};
static const int var{10};

void thread_func() {
    // 当前线程的线程id
    std::cout << "thread's id: " << std::this_thread::get_id() << "\n";

    // 线程睡眠5秒
    for (int i = 0; i < 5; i++) {
        if (notice) break;
        std::cout << "var: " << var << "\n";
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    std::cout << "thread: " << std::this_thread::get_id() << " ending\n";
}

int main() {
    // 主线程的id
    std::cout << "main thread: " << std::this_thread::get_id() << "\n";

    // 创建一个线程: 函数指针形式
    std::thread t1{thread_func};

    std::cout << "t1 start runing!\n";

    if (t1.joinable()) t1.join();

    std::cout << "t1 stop runing\n";

    // 线程对象的管理也很重要
    {
        // std::thread t2{thread_func};
    }  // 当执行到此 t2这个对象被销毁,但是子线程还会继续执行
    // 就会带来错误行为,Linux上直接abort进程

    {
        // 采用分离线程的方式
        // std::thread t2{thread_func};
        // std::cout << "t2 is runing\n";
        // 此时t2被销毁,线程继续执行是不影响的,但是
        // 主线程如果先一步子线程退出,子线程还在访问var
        // 那么也会产生错误行为,因为主线程退出整个进程的
        // 资源都会被系统回收
        // 会被libc++api直接terminating
    }
    {
        // 采用通过全局原子类型变量通知子线程可以退出
        // 的方式管理线程对象
        // 当主线程执行完毕,线程对象即将要被销毁之前
        // 改变全局原子类型变量的值通知子线程结束
        std::thread t2{thread_func};
        // 主线程休息3秒
        std::this_thread::sleep_for(std::chrono::seconds(3));
        // 通知子线程退出
        notice = true;

        if (t2.joinable()) t2.join();

        std::cout << "t2 is stop runing\n";
    }

    return 0;
}
