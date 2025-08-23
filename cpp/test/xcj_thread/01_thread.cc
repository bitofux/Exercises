/****************************************************
 * @file    01_thread.cc
 * @brief   第一个多线程程序
 *          熟悉C++11下的chrono库
 * @author  bitofux
 * @date    2025-08-23
 ****************************************************/
#include <iostream>
#include <thread>
#include <chrono>

void thread_func() {
    // 当前线程的线程id
    std::cout << "thread's id : " << std::this_thread::get_id() << "\n";

    // 让此线程睡眠5秒
    for (int i = 0; i < 5; i++) {
        std::cout << "i: " << i << "\n";
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    std::cout << "thread: " << std::this_thread::get_id() << " ending\n";
}
int main() {
    // 输出main线程的线程id
    std::cout << "id of main thread: " << std::this_thread::get_id() << "\n";
    // 创建一个线程:函数指针形式
    std::thread t1{thread_func};

    // 等待子线程执行完毕
    if (t1.joinable()) {
        t1.join();
    }

    return 0;
}
