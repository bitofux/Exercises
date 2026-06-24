/*
 * PROJECT : DAY8
 * FILE    : 1.istream.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-06-13
 * BRIEF   : 标准输入流
 */
#include <iostream>
#include <istream>
#include <limits>

using std::cin;
using std::cout;
using std::istream;

void print_state(istream& is) {
    cout << "good: " << is.good() << std::endl;
    cout << "fail: " << is.fail() << std::endl;
    cout << "bad: " << is.bad() << std::endl;
    cout << "eof: " << is.eof() << std::endl;
}

void test() {
    cout << "imput a num: ";
    int num = 0;
    cin >> num;
    std::cout << "num: " << num << std::endl;
    print_state(cin);
    cin >> num;
    std::cout << "num: " << num << std::endl;
    print_state(cin);
}

// 循环读取，检查流的状态
void test1() {
    int num = 0;

    // 循环读取
    while (true) {  // cin >> num这个表达式返回的是istream&，且可转换为bool
        cout << "imput a num: ";
        cin >> num;
        if (cin.fail() && !cin.bad()) {
            // 清理状态
            cin.clear();
            // 清空缓冲区
            // std::numeric_limits<std::streamsize>::max()是已丢弃的最大字符数量
            // 但是默认的终止符是EOF，但如果遇不到EOF，且未达到丢弃的最大字符数量，则会阻塞该进程
            // 对于这种标准输入流，建议改变终止符为'\n'，EOF在文件输入输出流常见
            cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            // 重新读取
            continue;
        }

        if (cin.bad()) {
            std::cout << "bad" << std::endl;
            return;
        }

        if (cin.eof()) {
            std::cout << "eof" << std::endl;
            return;
        }
        std::cout << "num: " << num << std::endl;
    }
}

int main() {
    // test();
    test1();
    return 0;
}
