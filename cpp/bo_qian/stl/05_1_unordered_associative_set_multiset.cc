/****************************************************
 * @file    05_1_unordered_associative_set_multiset.cc
 * @brief   C++11引入了无序关联容器:
 *          unordered_set,unordered_multiset
 *          unordered_map,unordered_multimap
 *          容器内的元素是不确定的,且顺序可能随时间变化
 *          其内部实现采用哈希表结构:由链表构成的数组
 *          该数组称为桶数组(array of buckets)
 *          链表则称为条目(entries)
 *          哈希函数根据元素值计算哈希值,根据该值将元素
 *          插入对应条目的指定位置
 *          这种结构的最大优势在于当哈希函数设计得当时
 *          在哈希表中查找元素的速度极快.仅需常数时间
 *          这是所有容器中最快的查找速度:
 *          O(n) -> O(log(n)) -> O(1)
 *
 *          multiset允许元素重复
 *          unordered_map/multimap与map/multimap相比
 *          就是多了无序
 *
 *          虽然哈希表提供了常数时间的查找,但是哈希碰撞
 *          可能会导致性能退化
 *
 *          哈希碰撞指多个元素被插入同一个桶中.退化的
 *          哈希表可能出现大部分元素集中在少数桶的情况.
 *
 *          最坏的情况下,所有元素被挤入单个桶,那么此时
 *          查找所消耗的时间从常数时间退化到线性时间
 *
 *          无序容器的特性:
 *              1. 支持任意位置的快速插入与查找:O(1)
 *              2. 而关联容器对数时间:O(log(n))
 *              3. vector deque需要线性时间
 *              4. list在已知插入位置时,插入:O(1)查找O(n)
 *              与关联容器一样,unordered_set/multiset
 *              不支持修改value,unordered_map/multimap
 *              不支持修改key.
 * @author  bitofux
 * @date    2025-08-19
 ****************************************************/
#include "03_containers.hpp"

int main() {
    std::unordered_set<std::string> myset{"red", "green", "blue"};
    // 如果找到这个元素,则返回指向该元素的迭代器
    // 否则返回指向容器末尾的迭代器
    std::unordered_set<std::string>::const_iterator itr{myset.find("green")};  // O(1)
    // 因此在解引用这个itr之前,需要检查itr
    // 是否指向了容器末尾,否则解引用末尾迭代器会导致
    // 未定义行为
    if (itr != myset.end()) {
        std::cout << *itr << "\n";
    }
    myset.insert("yellow");  // O(1)
    // 与其他容器的结合使用
    std::vector<std::string> vec{"purple", "pink"};
    myset.insert(vec.begin(), vec.end());
    for (const auto& ref : myset) {
        std::cout << ref << "\n";
    }

    // Hash table specific APIS.
    // load_factor函数返回当前哈希表的负载因子
    // 元素总量与桶数量的比值
    std::cout << "load_factor = " << myset.load_factor() << "\n";
    std::string x{"red"};
    // bucket函数可定位元素x所在的桶
    std::cout << x << " is in bucket #" << myset.bucket(x) << "\n";
    // 返回桶的总数
    std::cout << "Total bucket #" << myset.bucket_count() << "\n";
    return 0;
}
