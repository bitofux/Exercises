/****************************************************
 * @file    02_overview.cc
 * @brief   算法 -> 迭代器(iterator) -> 容器 
 *          代码复用,必须重复造轮子
 *          效率很高 标准库经过高度优化
 *          准确且错误较少
 *          简化代码
 *          容器与算法都有可读性很高的命名
 *          标准化库 所有平台可用
 *          if you don't learn them,you don't know what
 *          you are missing.
 * @author  bitofux
 * @date    2025-08-17
 ****************************************************/
#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec;
    vec.reserve(3);
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);//vec: {1,2,3}

    //vector的迭代器接口
    std::vector<int>::iterator iter1 {vec.begin()};
    std::vector<int>::iterator iter2 {vec.end()};
    //半开区间 [begin,end)

    for (std::vector<int>::iterator iter = iter1; iter != iter2;iter++) {
        std::cout << *iter << " ";
    }


}
