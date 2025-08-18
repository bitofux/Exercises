/****************************************************
 * @file    03_2_deque.cc
 * @brief   deque:双端队列
 *          可在首尾两端进入插入和删除:效率很高
 *          开头和末尾的插入和删除效率很高:O(1)
 *          中间的插入和删除效率很低:O(n)
 *          查找的效率低:O(n)
 *          支持随机访问 []
 * @author  bitofux
 * @date    2025-08-18
 ****************************************************/
#include "03_containers.hpp"

int main() {
    using deq_t = std::deque<int>;
    deq_t deq{4, 6, 7};
    // 在开头插入
    deq.push_front(2);  // {2,4,6,7}
    deq.push_back(10);  // {2,4,6,7,10};

    // 虽然不明确deque元素地址是否是连续
    // 但是支持随机访问
    std::cout << deq[2] << "\n";  // 6

    return 0;
}
