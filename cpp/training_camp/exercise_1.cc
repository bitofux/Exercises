// 题目描述:编写一个C++程序，要求用户输入两个整数(使用int类型),然后输出它们的和、差、积和商(使用float或double以避免整数除法问题)
#include <iostream>

int main() {
  // 定义两个保存用户输入整数的int类型变量
  int integer_one = 0;
  int integer_two = 0;

  // 提示用户输入两个整数
  std::cout << "输入两个整数(空格隔开): ";
  std::cin >> integer_one >> integer_two;

  // 输出这两个整数的和、差、积和商
  std::cout << "integer_one + integer_two = " << integer_one + integer_two
            << "\n";
  std::cout << "integer_one - integer_two = " << integer_one - integer_two
            << "\n";
  std::cout << "integer_one * integer_two = " << integer_one * integer_two
            << "\n";
  std::cout << "integer_one / integer_two = " << static_cast<float>(integer_one) / integer_two 
            << "\n";

  return 0;
}
