/****************************************************
 * @file    chrono.cc
 * @brief   C++的时间库
 * @author  bitofux
 * @date    2025-10-12
 ****************************************************/
#include <algorithm>
#include <iostream>
#include <chrono>
#include <thread>
#include <vector>

using std::cout;
using std::endl;

using namespace std::chrono;

// 三件事: durations,time points,clocks
// durations是一种存储时间长度的简单类型
// 它可以是秒的持续时间、小时的持续时间或者纳秒的持续时间
void test_duration() {
    // 定义一个5秒的持续时间，我会写类似的代码
    std::chrono::seconds five_seconds{std::chrono::seconds(6)};
    // 所有常用的持续时间都有内置的字面量
    auto five_seconds_ = 5s;
    // 有了持续时间，让我们用它做点什么
    // 可以让一个线程睡眠5秒钟
    std::this_thread::sleep_for(five_seconds);
}

void test_time_point() {
    // 获取当前时间点
    auto old = std::chrono::steady_clock::now();

    std::vector<int> vec{1000};
    std::cout << std::count_if(vec.begin(), vec.end(), [](int i) { return i == 0; }) << "\n";

    // 执行一系列之后的时间点减去之前获取的时间点
    // 就是一段持续的时间
    auto dur = std::chrono::steady_clock::now() - old;

    // std::cout << dur.count() << "\n";
    std::cout << duration_cast<microseconds>(dur).count() << "\n";
}
// 验证steady_clock::now返回的time_point
// 是以毫秒还是纳秒为单位
void test_steady_clock() {
    using clock = std::chrono::steady_clock;
    using dur = clock::duration;
    std::cout << "单位比率: " << dur::period::num << "/" << dur::period::den << "秒\n";
}
int main() {
    test_time_point();
    test_steady_clock();
}
