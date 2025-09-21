/****************************************************
 * @file    02_std_vector.cc
 * @brief   简单的介绍vector
 *          底层数据结构是一种动态数组
 *          支持随机访问和线性扩容
 *           元素访问:
 *              at():异常安全
 *              []: 异常不安全
 *              front(): 返回头部元素
 *              back(): 返回末尾元素
 *              data(): 返回底层数据结构的首个元素的地址
 *           一些修改操作:
 *           insert,emplace(),push_back,emplace_back()
 *           pop_back(),resize(),swap(),rease(),clear()
 * @author  bitofux
 * @date    2025-09-21
 ****************************************************/
#include <iostream>
#include <vector>

int main() {
    // 定义
    std::vector<int> vec;
    std::vector<int> vec1{5, 20};
    std::vector<int> vec2{1, 2, 3, 4, 5, 6};

    // 访问元素
    std::cout << "vec2[2]: " << vec2[2] << "\n";
    vec1.at(0) = 20;
    std::cout << "vec[0]: " << vec1[0] << "\n";
    return 0;
}
