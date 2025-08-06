//编写一个函数void reverseString(char* str),该函数接收一个字符数组(C语言中的字符串)作为参数,并就地(in-place)反转该字符串. 注意,字符串以\0结尾.

#include <cstring>
#include <iostream>
//反转字符串
void reverseString(char* str) {
  if (str == nullptr) {
    return;
  }
  //计算字符串中有多少个非空字符
  size_t len = strlen(str);
  //保存指向最后一位非空字符的地址
  char* ptr_end = str + len - 1;
  //反转字符串
  while (str < ptr_end) {
    char tmp = *str;
    *str = *ptr_end;
    *ptr_end = tmp;
    str++;
    ptr_end--;
  }
}
int main() {
  char str[] = "abcedf";
  reverseString(str);
  std::cout << str << "\n";

  return 0;
}
