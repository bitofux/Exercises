/*编写一个C++程序，展示nullptr与NULL(或0)在类型安全方面的区别。程序应该包含至少两个函数，一个接收int*类型参数，另一个接收int类型参数。在调用这两个函数时，分别使用nullptr，NULL和0作为参数，并观察编译器的警告或错误(如果有的话)*/

#include <iostream>

void funcPtr(int* ptr) {
  std::cout << "foo(int*)\n";
}

void funcInt(int integer) {
  std::cout << "funcInt(int)\n";
}

int main() {
  //调用funcPtr
  //1. 传入参数nullptr
  funcPtr(nullptr);
  //2. 传入参数NULL
  funcPtr(NULL);
  //3. 传入参数0
  funcPtr(0);
  /*调用funcPtr函数时,分别传入nullptr、NULL、0.编译器开启Wall Wextra等选项,除了函数中的形式参数没有使用的警告外无其他警告和错误*/

  //调用funcInt
  //1. 传入参数nullptr 
  //funcInt(nullptr);
  std::cout << "调用funcInt并传入nullptr时,出现编译错误。错误的详细信息是没有可匹配nullptr的函数，且出现一个note，详细信息为候选函数不可用：没有已知的方法可以将 std::nullptr_t 转换为 int 作为第 1 个参数\n";
  //2. 传入参数NULL
  funcInt(NULL);
  std::cout << "调用funcInt并传入NULL时,出现编译警告，即发生了一次隐式转换,是NULL常量转换为int类型\n";
  //3. 传入参数0
  funcInt(0);
  std::cout << "调用funcInt函数传入0时编译成功\n";

  std::cout << "-------------------------\n";

  std::cout << "1. 当一个函数的参数或一个变量的类型是指针类型时应该使用nullptr，因为NULL和0在c++中是一个整型常量\n";
  std::cout << "2. 使用nullptr可以不用担心形式参数是整型和指针类型的的函数重载\n";
  std::cout << "3. nullptr是有类型的，更好的支持模板编程\n";
  std::cout << "4. 由于nullptr是有类型的，当有异常抛出,就可以抛出nullptr\n";
  std::cout << "5. 同样的，当一个函数的参数是整型时，传入NULL会带来不必要的隐式转换\n";

  return 0;
}
