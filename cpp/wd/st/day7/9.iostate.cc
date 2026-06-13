/*
 * PROJECT : DAY7
 * FILE    : 9.iostate.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-06-13
 * BRIEF   : 流的状态，以标准输入流为例
 */
#include <iostream>
#include <istream>

using std::cin;
using std::cout;
using std::istream;

void print_state(istream& is) {
    std::cout << "good: " << is.good() << std::endl;
    std::cout << "fail: " << is.fail() << std::endl;
    std::cout << "bad: " << is.bad() << std::endl;
    std::cout << "eof: " << is.bad() << std::endl;
}
void test() {
    std::cout << "input a num: ";
    int num = 0;
    cin >> num;
    print_state(cin);
}

int main() {
    test();

    return 0;
}
