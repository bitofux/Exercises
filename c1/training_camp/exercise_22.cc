/*编写一个C++程序
 * 其中包含一个匿名命名空间
 * 在这个匿名命名空间中
 * 定义一个全局变量counter和一个函数incrementCounter
 * 该函数负责将counter的值增加1。然后，在main函数中
 * 通过调用incrementCounter函数多次
 * 并打印每次调用后的counter值，来验证匿名命名空间的作用和
 * 效果
 * */

#include <iostream>

namespace {
int counter = 0;
void incrementCounter() {
  counter++;
}
} //namespace;

int main() {
  int i = 0;
  while (i < 4) {
    incrementCounter();
    std::cout << "counter : " << counter << "\n";
    i++;
  }
}
