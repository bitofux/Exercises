/*
 * PROJECT : EXERCISES
 * FILE    : test_random.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-07-02
 * BRIEF   : 随机数
 */
#include <iostream>
#include <random>

int main() {
    // 初始化随机设备，获取操作系统的硬件熵作为种子
    std::random_device rd;

    // 初始化随机数引擎，利用梅森旋转算法
    std::mt19937 gen{rd()};

    // 定义一个闭区间 [1, 100] 的均匀整数分布
    std::uniform_int_distribution<> distrib(1, 100);

    for (int i = 0; i < 100; i++) {
        std::cout << distrib(gen) << " " << std::endl;
    }

    std::cout << std::endl;
}
