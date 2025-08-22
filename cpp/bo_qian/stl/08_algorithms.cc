/****************************************************
 * @file    08_algorithms.cc
 * @brief   算法: 本质上就是循环
 * @author  bitofux
 * @date    2025-08-22
 ****************************************************/
#include <algorithm>
#include "03_containers.hpp"

void test_algorithms() {
    std::vector<int> vec{4, 2, 5, 1, 3, 9};
    //查找vec中的最小元素
    std::vector<int>::iterator itr{std::min_element(vec.begin(), vec.end())};
    std::cout << *itr << "\n";
}
int main() {
    test_algorithms();

    return 0;
}
