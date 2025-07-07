// 编写一个程序，使用while循环计算并打印1到10的累加和

#include <iostream>

int main() {

  size_t i = 1, sum = 0;

  while (i <= 10) {
    sum += i;
    i++;
  }

  std::cout << "sum = " << sum << "\n";

  return 0;
}
