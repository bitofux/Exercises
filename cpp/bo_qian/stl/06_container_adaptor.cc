/****************************************************
 * @file    06_container_adaptor.cc
 * @brief   三种容器适配器:
 *              容器适配器基于基础容器实现,通过受限接口
 *              满足特定需求
 *              1. stack: LIFO push() pop() top()
 *              2. queue: FIFO push() pop() front()
 *                        back()
 *              3. priority queue: 一种包含不同优先级
 *                                 元素的队列.队首元素
 *                                 始终具有最高优先级
 *                                 push() pop() top()
 *
 *          还有一种容器的分类方式:
 *              1.基于数组的容器: vector deque
 *              2.基于节点的容器: list + associative
 *                                containers + unordered
 *                                containers
 *          这样区分的重要性在于基于数组的容器会使指针
 *          失效.这个指针包括原生指针(native pointer),
 *          迭代器(iterator)和引用(reference)
 *
 *          从下面的例子可以看出每次从vector中删除元素
 *          或者插入元素时,之前指向vector元素的指针可能会
 *          失效.因此要避免像下面的例子那样使用原生指针
 *
 *          基于节点的容器不会出现这种失效情况
 * @author  bitofux
 * @date    2025-08-19
 ****************************************************/
#include "03_containers.hpp"

int main() {
    std::vector<int> vec{1, 2, 3};
    int* p = &vec[2];  // p指向3
    // 此时通过迭代器在开头插入一个元素0
    vec.insert(vec.begin(), 0);
    // 运气好输出2,运气不好就是随机数或者程序崩溃
    // 程序崩溃应该是运气不错,总之就是未定义行为
    std::cout << *p << "\n";  // 2.or ?
}
