/****************************************************
 * @file    05_2_associative_array_map.cc
 * @brief   关联数组:[]运算符内可不一定只有数字
 *          关联数组可通过map与unordered_map实现,
 *          不可使用multimap和unordered_multimap,它们没有
 *          []运算符.因为它们中的key是可以重复的
 *
 *          unordered_map查找的时间是O(1),unordered_map
 *          查找的时间是O(log(n));但是要注意unordered_map
 *          可能会退化为线性时间.
 * @author  bitofux
 * @date    2025-08-19
 ****************************************************/
#include <utility>
#include "03_containers.hpp"

int main() {
    std::map<char,std::string> day {{'S',"Sunday"},{'M',"Monday"}};
    //不检查
    std::cout << day['S'] << std::endl;
    //检查
    std::cout << day.at('M') << std::endl;

    //可通过[]插入元素
    day['W'] = "Wednesday";//inserting {'W',"Wednesday"}
    //通过make_pari插入元素
    day.insert(std::make_pair('F', "Friday"));

    //不能通过insert去修改某个key对应的value
    //下面操作是失败的,因为这是map且已有'M' key
    day.insert(std::make_pair('M', "MONDAY"));

    //可以通过[]去修改value,但不可修改key
    day['M'] = "MONDAY";
    for (const auto& ref : day) {
        std::cout << ref.first << " => " << ref.second << "\n";
    }

}
