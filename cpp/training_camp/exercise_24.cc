/*编写一个C++程序，定义一个整型指针int* ptr,并使用nullptr初始化它。然后，编写一个条件判断语句来检查ptr是否为空，如果是，则打印一条消息表示指针未指向有效内存。
 * */
#include <iostream>

int main() {
  int* ptr = nullptr;

  //判断是否为空
  if (ptr == nullptr) {
    std::cout << "ptr is nullptr\n";
  }

  return 0;
}
