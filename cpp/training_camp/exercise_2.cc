// 识别并列出下面每个变量的作用域
#include <iostream>

int globalVar = 10;

namespace MyNamespace {
int namespaceVar = 20;
}

void myFunction(int paramVar) {
  int localVar = 30;
  std::cout << globalVar << ", " << MyNamespace::namespaceVar << ", "
            << paramVar << ", " << localVar << std::endl;
}

int main() {
  int mainLocalVar = 40;
  myFunction(50);
  std::cout << mainLocalVar << std::endl;
  return 0;
}
