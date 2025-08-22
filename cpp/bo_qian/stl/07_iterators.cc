/****************************************************
 * @file    07_iterators.cc
 * @brief   iterators的分类:
 *          1. random access iterator:随机访问迭代器
 *          2. bidirectional iterator:双向迭代器
 *          3. forward iterator: 前向迭代器
 *          4. input iterator: 输入迭代器
 *          5. output iterator: 输出迭代器
 * @author  bitofux
 * @date    2025-08-19
 ****************************************************/
#include <forward_list>
#include "03_containers.hpp"

/*
 * 每个容器都有一个迭代器和一个const迭代器(仅只读访问容器元素)
 * */

/*iterator functions
 *  1.advance(itr,5); move itr forward 5 spots. itr += 5;
 *  2.distance(itr1,itr2);测量两个迭代器的距离 
 * */

int main() {
    // 1.随机访问迭代器:vector array deque
    std::vector<int>::iterator itr;
    // 支持加减
    itr = itr + 5;
    itr = itr - 4;
    // 支持比较
    // if (itr2 > itr1) ...
    // 支持自增自减运算符
    // 前置++的效率要比后置++要高
    // 因为后置需要返回旧值,且返回旧值需要创建临时变量保存
    ++itr;
    --itr;

    // 2.双向迭代器:list set/multiset map/multimap
    std::list<int>::iterator itr1;
    // 支持自增运算符,不支持加减和比较
    ++itr1;
    --itr1;

    // 3.前向迭代器: forward_list
    std::forward_list<int>::iterator itr2;
    // 支持自增运算符,只能前进不可后退
    ++itr2;

    // 4.输入迭代器:用于在向前迭代时读取并处理数据
    //              可通过解引用用来读取输入迭代器的值
    //              不能对其进行写入操作
    // int x = *itr;

    // 5.输出迭代器:用于在向前迭代时输出值
    //              可通过解引用的输出迭代器写入数据
    //              但无法从中读取数据
    //*itr = 100;

    /*输入和输出迭代器仅支持单向向前移动,无法向后移动
     * 因此它们的功能是前向迭代器的子集*/
}
