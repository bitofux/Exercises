// 编写一个C++程序，展示静态局部变量和全局变量的区别
// 程序应包括一个函数，该函数内部有一个静态局部变量和
// 一个全局变量，函数被多次调用时，观察并记录两个变量
// 的行为
#include <iostream>

// 作用域是文件作用域，在当前翻译单元定义此变量之后有效
// 生命周期是进程级且在编译期就已初始化
int global_var = 10;

void test() {
    // 作用域仅在test函数体内
    // 生命周期是进程级
    // 只会在第一次调用函数初始化局部静态变量
    static int local_static_var = 0;

    local_static_var++;
    std::cout << "local_static_var: " << local_static_var << " ,global_var: " << global_var << '\n';
}

int main() {
    test();
    global_var++;

    test();
    global_var++;

    test();

    return 0;
}
