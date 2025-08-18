/****************************************************
 * @file    03_3_list.cc
 * @brief   list:双向链表
 *          在任意位置删除和插入效率很高:O(1)
 *          查找效率低:O(n),这比vector效率低得多
 *          这是因为局部性原理,现代处理器的计算瓶颈
 *          主要在于内存访问,因为处理器需要缓存
 *          vector将数据存储在连续的内存块中
 *          这意味着当整块内存载入缓冲时,缓存内数据
 *          利用率更高,缓存命中率更高.缓存更青睐
 *          连续存储的数据.而list的每个元素分散在内存
 *          不同位置,遍历list时会产生大量缓存未命中.
 *          这导致数据在缓存中频繁调入调出,会显著降低
 *          程序性能.许多STL已优化list的内存布局使其
 *          数据相对集中,但即便如此,由于每个元素包含
 *          两个指针,其内存占用仍大于等量元素的vector
 *          更大的内存占用意味着更多缓存未命中和缺页
 *          终端.因此list查找会更慢.
 *          虽有优缺点,但是list有一个很大的有点,那就是
 *          splice,时间复杂度为O(1)
 *          它有四个参数,第一个是要splice的list的指向
 *          某个位置的迭代器
 *          第二个是另外一个list 第三个第四个都是迭代器
 *          用于确定另外一个list的数据范围
 *          不支持随机访问 没有[]运算符
 * @author  bitofux
 * @date    2025-08-18
 ****************************************************/
#include "03_containers.hpp"

int main() {
    std::list<int> mylist {5,2,9};
    //尾部插入
    mylist.push_back(6); //mylist: {5,2,9,6}
    mylist.push_front(4); //mylist: {4,5,2,9,6}
    
    //查找元素为2
    auto itr {std::find(mylist.begin(),mylist.end(),2)};
    //在itr指向的位置插入元素8
    mylist.insert(itr,8); // mylist: {4,5,8,2,9,6}

    itr++; //itr指向2的下一个元素 9
    //删除itr当前指向的元素:9
    mylist.erase(itr); // mylist: {4,8,5,2,6} 

    std::list<int> mylist2 {2,-3,-4,-5,-6,7,8};

    auto iter1 {std::find(mylist2.begin(),mylist2.end(),2)};
    auto iter2 {std::find(mylist2.begin(),mylist2.end(),7)};
    

    //splice
    mylist.splice(mylist.end(),mylist2,iter1,iter2);

    for (auto& ref : mylist) {
        std::cout << ref << " ";
    }
    std::cout << "\n";

    return 0;
}
