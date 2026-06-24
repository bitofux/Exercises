/*
 * PROJECT : DAY8
 * FILE    : 2.ostream.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-06-13
 * BRIEF   : 标准输出流
 */
#include <iostream>
#include <ostream>
#include <unistd.h>

using std::cout;
using std::endl;
using std::ostream;

// 测试全缓冲，clang++编译器缓冲区空间4096个字节
// 输出字节数小于等于4096个字节，不显式刷新缓冲区。那么进程过了3秒之后
// 终端才显示这么多个'a'，能输出是因为进程结束之后自动刷新缓冲区
void test() {
    for (int i = 0; i < 4096; ++i) {
        std::cout << "a";
    }

    // 睡眠3秒
    sleep(3);
}

// 测试全缓冲，输出字符个数大于4096个，假设输出4097个字符，那么会输出到终端4096个字符
// 还有1个字符在缓冲区，等到进程结束之后，才刷新缓冲区输出
void test1() {
    for (int i = 0; i < 4097; ++i) {
        std::cout << "a";
    }

    sleep(3);
}

extern void test2();

// 无缓冲区的错误流
void test3() {
    for (int i = 0; i < 5; ++i) {
        std::cerr << "a";
    }
    sleep(5);
}
int main() {
    // test();
    // test2();
    test3();

    return 0;
}

// 测试全缓冲，使用endl刷新缓冲区并插入换行符
void test2() {
    for (int i = 0; i < 5; ++i) {
        std::cout << "a";
    }
    // 刷新并插入换行符
    std::cout << std::endl;

    sleep(3);
}
