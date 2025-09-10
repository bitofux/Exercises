#include "test.hpp"
#include <iostream>
// 函数模板的定义
template <typename T>
bool compare(T a, T b) {
    std::cout << "compare\n";
    return a < b;
}

