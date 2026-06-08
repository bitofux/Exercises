/*
 * PROJECT : DAY1
 * FILE    : 03_special_namespace.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-05-30
 * BRIEF   : 特殊的命名空间
 *            1. 命名空间嵌套
 *            2. 匿名命名空间
 */
#include <iostream>

using std::cout;
using std::endl;

// 1. 命名空间嵌套
namespace wd {
int num1 = 1;
namespace cpp {
int num1 = 10;
}
}  // namespace wd

void test() {
    // 命名空间嵌套的使用 建议还是作用域限定符访问最好
    // 使用using编译指令和using声明和普通一层的命名空间
    // 是一样的
    cout << "wd::num1: " << wd::num1 << "\n";
    cout << "wd::cpp::num1: " << wd::cpp::num1 << "\n";
}

// 2. 匿名命名空间
namespace {
int num = 10;

double d1 = 20.2;
}  // namespace

// 定义一个与匿名命名空间重名的全局实体
int num = 20;
void test1() {
    // 匿名命名空间内实体的访问和全局差不多
    // 可直接使用，但全局实体若有重名的实体
    // 则会产生二义性
    // 若使用作用域限定符访问的话，输出的是全局实体
    // cout << num << "\n";
    cout << d1 << "\n";

    // 输出的是全局实体
    cout << ::num << "\n";
}
// 匿名空间特点：相当于是一个被static修饰的全局变量，它的链接性为内部链接，不产生链接符号供其他翻译单元使用

int main() {
    // test();
    test1();

    return 0;
}
