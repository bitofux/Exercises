/*1.预处理时错误
 *2.编译时错误
 *3.运行时错误
 *4.警告*/
#include <iostream>

int main () {

  //编译时错误 少一个分号
  std::cout << "comp-time errors!" << std::endl

  //运行时错误 ➗0 解引用空指针 解引用悬空指针 未定义
  int var = 10 / 0;
  std::cout << "var: " << var << std::endl;

  int* p = nullptr;
  std::cout << *p << std::endl; 
  return 0;
}
