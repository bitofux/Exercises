/*
 * PROJECT : EXERCISES
 * FILE    : 1.introduction_thread.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-07-28
 * BRIEF   : 介绍多线程
 */
#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <random>
#include <thread>
#include <vector>
#include <array>
#include <chrono>

constexpr size_t DATA_SIZE = 2050000;

class BtxTimer {
public:
    BtxTimer() { start_ = std::chrono::steady_clock::now(); }

    double mark() noexcept {
        auto old = start_;
        start_ = std::chrono::steady_clock::now();
        std::chrono::duration<float, std::milli> dura = old - start_;

        return dura.count();
    }

    double peek() const noexcept {
        auto now = std::chrono::steady_clock::now();

        auto dura = std::chrono::duration_cast<std::chrono::milliseconds>(now - start_);

        return dura.count();
    }

private:
    std::chrono::time_point<std::chrono::steady_clock> start_;
};

// 未引入多线程之前: processing the database took 216 ms
void test() {
    // 随机种子
    std::random_device rd;
    // 随机数引擎
    std::minstd_rand mr(rd());
    // 随机数范围
    std::uniform_int_distribution<> distrib(100000, 600000);
    // 计时
    BtxTimer btimer;

    // 定义一个数据集
    std::vector<std::array<int, DATA_SIZE>> database{10};

    // 初始化
    for (auto arr : database) {
        std::generate(arr.begin(), arr.end(), [&mr, &distrib]() { return distrib(mr); });
    }

    btimer.mark();
    // 执行一些消耗CPU的计算
    for (auto& arr : database) {
        for (auto val : arr) {
            // 编译期获取int类型的最大值
            constexpr auto limits = (double)std::numeric_limits<int>::max();
            const auto y = (double)val / limits;

            arr[0] += int(std::sin(std::cos(y)) * limits);
        }
    }

    const auto t = btimer.peek();

    std::cout << "processing the database took " << t << " ms\n";
}

// 引入多线程
void test_thread_one() {
    // 随机种子
    std::random_device rd;
    // 随机数引擎
    std::minstd_rand mr(rd());
    // 随机数范围
    std::uniform_int_distribution<> distrib(100000, 600000);
    // 计时
    BtxTimer btimer;

    // 创建元素类型为std::thread的vector容器
    std::vector<std::thread> workers;

    // 定义一个数据集
    std::vector<std::array<int, DATA_SIZE>> database{10};

    // 初始化
    for (auto arr : database) {
        std::generate(arr.begin(), arr.end(), [&mr, &distrib]() { return distrib(mr); });
    }

    btimer.mark();
    // 根据数据集的个数创建对应的线程对象
    for (auto& set : database) {
        auto work = [](decltype(set) my_set) {
            for (auto val : my_set) {
                constexpr auto limits = (double)std::numeric_limits<int>::max();
                auto y = (double)val / limits;
                my_set[0] += std::sin(std::cos(y) * limits);
            }
        };

        // 创建一个线程对象，添加到workers容器中
        workers.push_back(std::thread{work,std::ref(set)});
    }

    // 等待其他子线程执行完毕，否则主线程先退出的话，资源释放，子线程会发生错误导致程序异常
    for (auto& thread : workers) {
        if (thread.joinable()) {
            thread.join();
        }
    }
    const auto t = btimer.peek();

    std::cout << "processing database took " << t << " ms\n";
}

int main() {
    // test();
    test_thread_one();
    return 0;
}
