/*编写一个C++函数，该函数接收一个整型指针int* ptr作为参数，并检查该指针是否为nullptr,如果不是nullptr，则函数应打印出指针所指向的整数值；如果是nullptr,则打印一条消息表示未接收到有效的指针。然后，在主函数中调用这个函数，并分别传递一个有效的整型指针和一个nullptr作为参数
 * */
#include <iostream>

void print(int* ptr) {
  if (ptr == nullptr) {
    std::cout << "未接收到有效的指针\n";
    return;
  } else {
    std::cout << "ptr指向的整数值: " << *ptr << "\n";
  }
}

int main() {
  int var = 10;
  // 1.传入有效的指针
  print(&var);

  //2.传入nullptr
  print(nullptr);

  return 0;
}
