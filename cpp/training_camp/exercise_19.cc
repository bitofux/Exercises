/*定义一个名为Math的命名空间
 * 在该命名空间中定义两个函数add和subtract
 * 分别用于执行加法和减法操作 
 * 在main函数中,
 * 通过完全限定名（即Math::add和Math::subtract）
 * 调用这两个函数。
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
  std::cout << "20 + 10 = " << Math::add(20, 10) << "\n";
  std::cout << "20 - 10 = " << Math::subtract(20, 10) << "\n";

  return 0;
}
