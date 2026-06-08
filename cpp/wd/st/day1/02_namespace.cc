/*
 * PROJECT : DAY1
 * FILE    : 02_namespace.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-05-30
 * BRIEF   : 命名空间
 */
#include <iostream>

using std::cout;
using std::endl;

// 定义wd命名空间
namespace wd {
// 可定义自己的实体，类型 对象 函数等等
int num = 1;
void func() { cout << "wd::func()" << endl; }
}  // namespace wd

// 定义cpp命名空间
namespace cpp {
int num = 10;
void func() { cout << "cpp::func()" << endl; }
}  // namespace cpp

// 方式一：使用作用域限定符访问命名空间中的实体
void test1() {
    // 访问wd命名空间中的实体
    cout << "wd::num: " << wd::num << "\n";
    cout << "wd::func()" << "\n";
    wd::func();

    // 访问cpp命名空间中的实体
    cout << "cpp::num" << cpp::num << "\n";
    cout << "cpp::func()" << "\n";
    cpp::func();
}

// 方式二：使用using编译指令
void test2() {
    // 将wd命名空间中的所有实体引入到当前作用域中的可见表
    using namespace wd;
    cout << "num: " << num << "\n";
    func();

    // 将cpp命名空间中的实体引入到当前作用域中的可见表
    // 若可见表中有重复的实体，则会引起二义性
    using namespace cpp;
    // cout << "num: " << num << "\n";  // 二义性
    // func();                          // 二义性
}

// 方式三：使用using声明
void test3() {
    // 将cpp命名空间中的特定实体引入到当前作用域中的定义表
    using cpp::num;
    cout << "num: " << num << "\n";

    // 若这时将wd命名空间中的num实体也使用using声明
    // 那将造成作用域内声明冲突
    // using wd::num;

    // 若使用using 编译指令
    // 则不使用作用域限定符的话，访问的是定义表的cpp中的num
    using namespace wd;
    cout << "num: " << num << "\n";
}

int main() {
    // test1();
    // test2();
    test3();

    return 0;
}
