#include <iostream>
#include "1_namespace_merge.h"
// 定义一个命名空间
namespace wd {
// 定义变量
int number = 20;
int count = 21;
// 定义函数
void display() { std::cout << "wd::display()" << std::endl; }
void print() { std::cout << "wd::print()" << std::endl; }
} // end of namespace wd


/*访问命名空间中的三种常见用法*/

//1.使用作用域解析运算符 ::
void test0() {
  //使用作用域解析运算符访问特定命名空间中的实体
  std::cout << "wd::number: " << wd::number << std::endl;
  std::cout << "wd::count: " << wd::count << std::endl;
}

//2.使用using-directive
void test1() {
  using namespace wd;//将命名空间中的所有实体引入到test1函数作用域内
  display();
  print();
}
//3. 使用using-declaration
void test2() {
  using wd::number;//引入命名空间中某个特定的实体到test2作用域内
  std::cout << "number: " << number << std::endl;
}

/*访问模块内tofu命名空间内的实体*/
void test3() {
  using namespace tofu;
  std::cout << "number: " << number << std::endl;
  std::cout << "variable: " << variable << std::endl;
  print();
  display();
}
int main() {
  // test0();
  // test1();
  // test2();
  test3();
}
