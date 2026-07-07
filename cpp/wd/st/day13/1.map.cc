/*
 * PROJECT : DAY12
 * FILE    : 1.map.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-07-07
 * BRIEF   : map关联容器
 */
#include <iostream>
#include <map>
#include <utility>

// map的构造
void test() {
    std::map<int, std::string> number{// 通过初始化列表方式创建pair对象
                                      {1, "hello"},
                                      {2, "world"},
                                      {3, "st"},

                                      // 直接通过构造函数创建pair对象
                                      std::pair<int, std::string>{4, "tafu"},
                                      std::pair<int, std::string>{5, "tofu"},

                                      // 通过make_pair方法创建pair对象
                                      std::make_pair(6, "bitofux")};
    // 在map容器内，会根据key值进行升序(默认)和去重。

    // 首先就是遍历容器：增强for循环
    for (auto& val : number) {
        std::cout << "key: " << val.first << "\nvalue: " << val.second << std::endl;
    }

    // 利用迭代器
    for (auto it = number.begin(); it != number.end(); ++it) {
        std::cout << "key: " << (*it).first << "\nvalue: " << (*it).second << std::endl;
    }
}

// map的查找
// count
// find
void test1() {
    std::map<int, std::string> number{
        std::make_pair(1, "bitofux"),
        std::make_pair(2, "tofu"),
        std::make_pair(3, "tafu"),
    };

    // 利用count查找key，找到返回1，找不到返回0
    auto result = number.count(1);
    auto result1 = number.count(4);
    std::cout << "result: " << result << std::endl;
    std::cout << "result1: " << result1 << std::endl;

    // 利用find查找key值，找到输出其对应的val
    auto iter = number.find(1);
    if (iter != number.end()) {
        std::cout << "val: " << (*iter).second << std::endl;
    } else {
        std::cout << "not found." << std::endl;
    }
}

// map插入单个元素
void test2() {
    std::map<int, std::string> number{
        std::make_pair(1, "bitofux"),
        std::make_pair(2, "tofu"),
        std::make_pair(3, "tafu"),
    };

    // 插入单个元素，使用的insert接口返回类型是pair<std::map<int,std::string>::iterrator,bool>类型
    // 前者指向元素的迭代器，若插入失败，后者是false，成功，后者是true
    std::pair<std::map<int, std::string>::iterator, bool> ret = number.insert({4, "wangshuai"});

    std::cout << "first: " << (*(ret.first)).first << "\nvalue: " << ret.second << std::endl;
}
// map插入多个元素
void test3() {
    std::map<int, std::string> number{
        std::make_pair(1, "bitofux"),
        std::make_pair(2, "tofu"),
        std::make_pair(3, "tafu"),
    };

    // 利用初始化列表插入多个元素
    number.insert({{4, "wangshuai"}, {5, "hello"}});

    std::cout << "size: " << number.size() << std::endl;
}

// 根据下标来修改已存在的key的value或者访问key对应的value值
void test4() {
    std::map<char, std::string> con{{'a', "bitofux"}, {'b', "bit"}, {'c', "hello"}};

    // 访问key为'a','b'的value
    std::cout << con['a'] << std::endl;
    std::cout << con['b'] << std::endl;

    // 访问一个不存在的key，默认会执行插入，相当于插入新的元素
    // value会是这个类型的默认值
    std::cout << con['d'] << std::endl;

    std::cout << con['d'] << std::endl;
    std::cout << con.size() << std::endl;

    // 修改key 'a'对应的value
    con['a'] = "wangdao";

    std::cout << con['a'] << std::endl;
}

int main() {
    // test();

    // test1();
    // test2();

    // test3();
    test4();
    return 0;
}
