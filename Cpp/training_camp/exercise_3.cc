/*编写一个程序，要求用户输入一个成绩(0-100之间的整数)，然后根据成绩输出等级(A,B,C,D,E)
等级划分如下： 90-100:A 80-89:B 70-79:C 60-69:D 0-59:E
*/
#include <iostream>

int main() {
  // 定义保存用户成绩的变量
  unsigned short score = 0;

  // 提示用户输入成绩
  std::cout << "输入您的成绩(0-100): " << "\n";
  std::cin >> score;

  // 输出用户成绩对应的等级
  if (score >= 90 && score <= 100) {
    std::cout << "A\n";
  } else if (score >= 80 && score <= 89) {
    std::cout << "B\n";
  } else if (score >= 70 && score <= 79) {
    std::cout << "C\n";
  } else if (score >= 60 && score <= 69) {
    std::cout << "D\n";
  } else {
    std::cout << "E\n";
  }

  return 0;
}
