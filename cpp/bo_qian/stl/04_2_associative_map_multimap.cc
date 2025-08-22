/****************************************************
 * @file    04_2_associative_map_multimap.cc
 * @brief   关联容器始终保持元素有序,但有时人们不想按照按
 *          元素值本身排序.而是希望根据特定键值进行排序.
 *          因此我们需要键值对 key -> value
 *          这就是map/multimap存在的原因
 *          map不允许key重复
 *
 *          multimap是允许重复key值的
 *          key是不允许修改的
 *          type of *it: std::pair<const char,int>
 *          (*it).first = 'd'; //error
 *
 *          set multiset map multimap都是关联容器
 *          那么关联具体值得是什么？这主要还是看
 *          key -> value的关联.至于set/multiset
 *          你可以将它们视为特殊的映射和多重映射,
 *          其中每个元素的key与value相同.
 *
 * @author  bitofux
 * @date    2025-08-19
 ****************************************************/
#include "03_containers.hpp"

int main() {
    std::map<char, int> mymap;
    // 插入元素时需要先创建char到int的键值对
    mymap.insert(std::pair<char, int>('a', 100));
    // 可以自动推导类型,减少编码量
    mymap.insert(std::make_pair('z', 200));

    std::map<char, int>::iterator it{mymap.begin()};
    // insert函数可接收迭代器参数作为插入位置的提示
    mymap.insert(it, std::make_pair('s', 300));

    // 成员函数find通过key值在map中查找元素
    it = mymap.find('z');  // O(log(n))

    // 可通过first和second成员访问键值对元素
    for (it = mymap.begin(); it != mymap.end(); ++it) {
        std::cout << it->first << " => " << it->second << "\n";
    }
}
