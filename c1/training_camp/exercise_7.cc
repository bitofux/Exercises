//编写一个函数 int factorial(int n),该函数接收一个整数n作为参数，并返回n的阶乘(n! = n * (n - 1) * ... * 2 * 1)),如果n < 0，则返回-1表示错误

#include <iostream>

//阶乘计算
int factorial(int n) {
  if (n < 0) {
    return -1;
  }

  if (n == 1 || n == 0) {
    return 1;
  }

  return n * factorial(n - 1);
}
int main() {
  //测试阶乘计算函数
  std::cout << "当n为0时: " << factorial(0) << "\n";
  std::cout << "当n为1时: " << factorial(1) << "\n";
  std::cout << "当n >= 2时: " << factorial(5) << "\n";

  return 0;
}
