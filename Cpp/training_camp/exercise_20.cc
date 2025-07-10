/*定义一个名为Math的命名空间
 * 在该命名空间中定义两个函数add和subtract
 * 分别用于执行加法和减法操作 
 * 在main函数中,
 * 通过完全限定名（即Math::add和Math::subtract）
 * 调用这两个函数。
 *
 * 在上一个题目的基础上
 * 修改main函数
 * 使用using声明来简化对Math命名空间中add函数的调用
 * 仍然通过完全限定名调用subtract函数
 * 以展示using声明的局部性。
 *
 * */

#include <iostream>

namespace Math {
int add(int a,int b) {
  return a + b;
}

int subtract(int a,int b) {
  return a - b;
}
} //namespace Math

int main() {
  using Math::add;
  std::cout << "20 + 10 = " << add(20, 10) << "\n";
  std::cout << "20 - 10 = " << Math::subtract(20, 10) << "\n";

  return 0;
}
