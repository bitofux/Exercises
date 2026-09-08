/*
 * PROJECT : EXERCISES
 * FILE    : 14.function_default_argument.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-09-08
 * BRIEF   : 函数默认参数
 */
#include <iostream>

// 函数声明
void createWindow(char const* title, int wight, int height, int x = 1, int y = 1);

// 函数定义
void createWindow(char const* title, int width, int height, int x, int y) {
    using namespace std;
    cout << "title: " << title << "\n";
    cout << "x: " << x << "\n";
    cout << "y: " << y << "\n";
    cout << "width: " << width << "\n";
    cout << "height: " << height << "\n";
}

int main() {
    createWindow("notepad", 100, 200);

    return 0;
}
