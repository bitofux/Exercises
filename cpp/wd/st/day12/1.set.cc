/*
 * PROJECT : EXERCISES
 * FILE    : set.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-07-07
 * BRIEF   : 关联容器set的简单使用
 */

#include <iostream>
#include <random>
#include <set>

using std::cout;
using std::endl;

// set的构造
void test() {
    // 1. 无参构造
    std::set<int> nums;

    // 2. 标准初始化列表构造
    std::set<int> nums1{1, 2, 3, 4, 5};

    // 3. 拷贝构造
    std::set<int> nums2{nums1};

    // 4. 迭代器构造
    std::set<int> nums3{nums1.begin(), nums1.end()};

    // 使用迭代器访问容器元素
    for (auto it = nums1.begin(); it != nums1.end(); it++) {
        std::cout << *it << std::endl;
    }

    // 使用增强for循环
    for (auto& val : nums1) {
        std::cout << val << std::endl;
    }
}

// set的查找与插入单个元素
void test1() {
    std::set<int> nums;

    // 插入一些随机整数
    std::random_device rd;

    std::mt19937 gen{rd()};

    std::uniform_int_distribution<> distrib(1, 10);

    for (int i = 0; i < 10; ++i) {
        auto val = nums.insert(distrib(gen));
        std::cout << "insert success: " << val.second << ",val: " << *(val.first) << std::endl;
    }

    // 输出此时容器中的元素值，应该是不会有重复且是升序的
    for (auto& val : nums) {
        std::cout << val << " ";
    }

    // 利用迭代器进行插入，在开头插入20
    nums.insert(nums.begin(), 20);
    // 输出的结果可能会因为排序的问题，20会被移动到末尾
    for (auto& val : nums) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

// 测试修改set中的元素
void test3() {
    std::set<int> nums;
    nums.insert(10);
    nums.insert(20);

    // 在容器中查找key为10
    auto it = nums.find(10);

    if (it != nums.end()) {
        // 修改该迭代器指向的key
        // *it = 30;不可以修改
    }
}

// 先删除，再插入
void test4() {
    std::set<int> nums;
    nums.insert(10);
    nums.insert(20);

    // 在容器中查找key为10
    auto it = nums.find(10);

    if (it != nums.end()) {
        // 先删除key为10
        nums.erase(it);
        // 插入新的元素30
        nums.insert(30);
    }
}
int main() {
    // test();
    test1();

    return 0;
}
