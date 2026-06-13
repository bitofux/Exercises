/*
 * PROJECT : DAY7
 * FILE    : 8.vector.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-06-13
 * BRIEF   : vector容器
 */
#include <iostream>
#include <vector>

using std::cout;
using std::endl;

// vector构造
void test() {
    // 1. 无参构造
    std::vector<int> numbers;
    std::cout << "size: " << numbers.size() << std::endl;

    // 2. 指定元素数量
    std::vector<int> numbers1{10};  // 存放10个0
    std::cout << "size: " << numbers1.size() << std::endl;

    // 3. 指定元素数量和值
    std::vector<int> numbers2{10, 20};  // 存放10个20的整数
    std::cout << "size: " << numbers2.size() << std::endl;

    // 4. 通过初始化列表构造vector
    std::vector<int> numbers3{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::cout << "size: " << numbers3.size() << std::endl;

    // 5. 使用迭代器的方式
    std::vector<int> numbers4{numbers3.begin(), numbers3.end() - 2};
    std::cout << "size: " << numbers4.size() << std::endl;
    for (const auto& val : numbers4) {
        std::cout << val << std::endl;
    }
}

// vector常用操作
void test1() {
    int arr[10]{2, 34, 21, 23, 34, 54, 56, 76, 78, 98};
    // 构造一个vector
    std::vector<int> vec{arr, arr + 6};

    // 判断vec是否为空
    if (vec.empty()) {
        std::cout << "vec is empty\n";
    } else {
        std::cout << "vec is not empty\n";
    }
    // vec有效元素的个数
    std::cout << "size: " << vec.size() << std::endl;  // 6

    // vec容量
    std::cout << "capacity: " << vec.capacity() << std::endl;  // 6

    // 插入一个元素，查看扩容
    vec.push_back(20);
    std::cout << "size: " << vec.size() << std::endl;          // 7
    std::cout << "capacity: " << vec.capacity() << std::endl;  // 12 两倍扩容
    vec.shrink_to_fit();                               // 清理掉未使用的空间，此时capacity = 7
    std::cout << "size: " << vec.size() << std::endl;  // 7
    std::cout << "capacity: " << vec.capacity() << std::endl;  // 7

    // 清空所有元素，但不释放空间
    // vec.clear();
    // std::cout << "size: " << vec.size() << std::endl; // 0
    // std::cout << "capacity: " << vec.capacity() << std::endl; // 7

    // 使用迭代器遍历vector
    auto it{vec.begin()};
    for (; it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";

    // 使用下标访问
    for (int i = 0; i < vec.size(); ++i) {
        std::cout << vec.at(i) << " ";
    }
    std::cout << std::endl;

    // 增强for循环
    for (auto& val : vec) {
        std::cout << val << " ";
    }
    std::cout << "\n";
}

int main() {
    // test();
    test1();
    return 0;
}
