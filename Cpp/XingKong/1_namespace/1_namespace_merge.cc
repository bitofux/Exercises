#include "1_namespace_merge.h"
#include <iostream>

// 命名空间可以在一个模块内多次定义
namespace tofu {
int number = 10;
int variable = 20;
void print() { std::cout << "tofu::print()" << std::endl; }
void display() { std::cout << "tofu::display()" << std::endl; }
} // namespace tofu
