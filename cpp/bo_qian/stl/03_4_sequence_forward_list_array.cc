/****************************************************
 * @file    03_4_forward_list_array.cc
 * @brief   forward_list: 单向链表
 *          std::array: 限制大小的数组
 *          且std::array<int,3>与std::array<int,4>不是
 *          同一个类型
 * @author  bitofux
 * @date    2025-08-18
 ****************************************************/
#include "03_containers.hpp"

int main() {
    std::array<int,3> arr {1,2,3};
    std::cout << arr[2] << std::endl;
    
    for ( auto itr{arr.crbegin()};itr!=arr.crend();itr++) {
        std::cout << *itr << std::endl;
    }
}
