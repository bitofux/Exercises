/*
 * PROJECT : EXERCISES
 * FILE    : 1.first_cpp_program.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-08-23
 * BRIEF   : 第一个 cpp 程序
 * -- 预处理：由预处理器执行
 *  1. 预处理器会处理所有以(#)开头的语句
 *  2. 若你的源代码中包含了任何头文件，预处理器会用相应文件的实际内容来替换这些include语句
 *  3. 源代码中定义的宏也会被展开；注释会被清除
 *
 * -- 编译：由编译器执行
 *  1. 检查代码的语法是否正确；代码优化等等
 *  2. 生成对应平台架构上的汇编指令
 *
 * -- 汇编：由汇编器执行
 *  1. 生成支持重定位的目标文件
 *  2. 目标文件中存放的是由汇编代码转换为的目标代码，其实就是原始二进制了
 *
 * -- 链接：由链接器执行
 *  1. 多个目标文件进行链接，完成符号解析和重定位
 *  2. 链接所需的静态库、动态库或者其他第三方库最后生成可执行文件
 */

// 单行注释

/*
 * 多行注释
 */

#include <iostream>

// 不使用using namespace
void test() { std::cout << "Hello " << "C++" << std::endl; }

int main() {
    // 使用using namespace
    using namespace std;
    cout << "Hello " << "C++" << endl;

    test();

    return 0;
}
