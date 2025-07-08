//编写一个函数int gcd(int a,int b),该函数接收两个整数a和b作为参数，并返回它们的最大公约数(GCD),你可以使用欧几里得算法来实现
#include <iostream>

int gcd(int a,int b) {
  if (a % b == 0) {
    return b;
  }

  while (true) {
    int rd = a % b;
    a = b;
    b = rd;
    if (a % b == 0) {
      break;
    }
  }

  return b;
}


int main() {
  std::cout << "gcd(18,12): " << gcd(2, 4) << "\n";
  return 0;
}
