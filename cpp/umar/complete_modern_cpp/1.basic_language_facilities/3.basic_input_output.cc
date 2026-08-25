/*
 * PROJECT : EXERCISES
 * FILE    : 3.basic_input_output.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-08-23
 * BRIEF   : 基本的输入输出
 */
#include <cstdio>
#include <iostream>

void test_input() {
    std::cout << "What is your name: ";
    char buffer[512]{0};

    std::cin.getline(buffer, 1, '\n');
    std::cout << std::cin.gcount() << std::endl;
    std::cout << "My name is " << buffer << std::endl;

    std::cout << "How old are you: ";
    int age = 0;
    std::cin >> age;
    std::cout << "Age is " << age << std::endl;
}
int main() {
    // using namespace std;
    //
    // std::cout << "Hello World\n" << 45 << "\n" << 8.2f << std::endl;

    test_input();

    return 0;
}
