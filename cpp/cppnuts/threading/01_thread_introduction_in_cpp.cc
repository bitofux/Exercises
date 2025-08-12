/****************************************************
 * @file    01_thread_introduction_in_cpp.cc
 * @brief   WAYS TO CREATE THREADS IN C++11
 *          1.Function Pointers       函数指针
 *          2.Lambda Function         匿名函数
 *          3.Functors                函数对象
 *          4.Member Functions        成员函数
 *          5.Static Member Functions 静态成员函数
 * @author  bitofux
 * @date    2025-08-12
 ****************************************************/
#include <iostream>
#include <thread>  //线程库
#include <chrono>
using ull = unsigned long long;

/*分别实现两个函数:
1.计算1到1900000000的奇数和
2.计算1到1900000000的偶数和
*/

// 计算偶数和
void findEven(ull start, ull end, ull* EvenSum) {
    for (ull i = start; i <= end; i++) {
        if (0 == (i & 1)) {
            *EvenSum += i;
        }
    }
}

// 计算奇数和
void findOdd(ull start, ull end, ull* OddSum) {
    for (ull i = start; i <= end; i++) {
        if (1 == (i & 1)) {
            *OddSum += i;
        }
    }
}
int main() {
    // 数字范围
    ull start = 0, end = 1900000000;

    // 保存奇数和，偶数和
    ull EvenSum{0}, OddSum{0};

    // 记录开始时间
    auto start_time{std::chrono::high_resolution_clock::now()};

#if 0
    findEven(start, end, &EvenSum);
    findOdd(start, end, &OddSum);
#endif

    // 使用线程
    std::thread t1{findEven, start, end, &EvenSum};
    std::thread t2{findOdd, start, end, &OddSum};

    if (t1.joinable()) t1.join();
    if (t2.joinable()) t2.join();
    // 记录结束时间
    auto end_time{std::chrono::high_resolution_clock::now()};
    auto duration{std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time)};

    std::cout << "OddSum: " << OddSum << std::endl;
    std::cout << "EvenSum: " << EvenSum << std::endl;

    // 输出执行时间
    std::cout << "sec: " << duration.count() / 1000000 << std::endl;

    return 0;
}
