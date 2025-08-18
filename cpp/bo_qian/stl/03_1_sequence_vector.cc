/****************************************************
 * @file    03_1_vector.cc
 * @brief   vector
 *          末尾插入和删除的效率很高:O(1)
 *          开头或中间的删除和插入效率低:O(n)
 *          查找效率低:O(n)
 *          支持随机访问 []
 * @author  bitofux
 * @date    2025-08-17
 ****************************************************/
#include "03_containers.hpp"

int main() {
    using vec_t = std::vector<int>;

    vec_t vec;  // vec.size() == 0
    vec.push_back(4);
    vec.push_back(1);
    vec.push_back(8);  // vec: {4,1,8} vec.size() == 3

    // vector operations:
    std::cout << vec[2]; // 8 (不进行范围检查)
    std::cout << '\n';
    std::cout << vec.at(2)  ; // 8 (在索引越界时会抛出rang_error exception)
    std::cout << '\n';

    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec.at(i) << " ";
    }

    for (vec_t::iterator iter = vec.begin(); iter!=vec.end(); iter++) {
        std::cout << *iter << " ";
    }

    for (auto& ref : vec) {
        std::cout << ref << " ";
    }

    std::cout << "\n";
    //由于vector在底层是使用动态数组的方式进行存储数据
    //那么vector中的元素的地址是连续的,因此也是可以使用
    //普通指针进行操作的
    int* ptr {&vec.at(0)};
    //使用ptr访问后两个元素
    for (int i = 0; i < 2;i++) {
        std::cout << *(ptr + i) << " ";
    }
    std::cout << "\n";

    //以下是三类容器实现的通用的api
    //判断容器是否为空
    if (vec.empty()) {
        std::cout << "not possible\n";
    }
    
    //容器元素个数
    std::cout << vec.size() << std::endl;

    //将当前容器内的元素拷贝到另外一个容器
    vec_t vec2 {vec};// vec2 = {4,1,8}
    //容器置空
    vec.clear();//移除容器内的所有元素
    
    //容器交换:O(1)
    vec.swap(vec2); // vec2为空,vec的元素是{4,1,8}

    return 0;
}
