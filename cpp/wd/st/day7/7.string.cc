/*
 * PROJECT : DAY7
 * FILE    : 7.string.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-06-12
 * BRIEF   : 熟悉一下C++中的string类，是一个对字符动态数组的封装
 */
#include <iostream>
#include <string>

// std::string 对象的构造
void test() {
    // 无参构造
    std::string name;  // 生成一个空字符串
    const char* ptr{name.c_str()};
    std::cout << "isspace: " << (ptr[0] == '\0') << std::endl;  // 1

    // 通过C风格字符串构造一个string对象
    std::string name_1{"bitofux"};
    std::cout << name_1.size() << std::endl;

    // 通过C风格字符串和前count个字符构造一个string对象
    std::string name_2{"bitofux", 4};
    std::cout << "name_2: " << name_2 << std::endl;
    std::cout << "name_2.size: " << name_2.size() << std::endl;

    // 通过已存在的string对象构造一个新的string对象
    std::string name_3{name_2};
    std::cout << "name_3: " << name_3 << std::endl;
    std::cout << "name_3.size: " << name_3.size() << std::endl;

    // 通过已存在string对象的一部分构造一个新的string
    std::string name_4{name_1, 2, 4};
    std::cout << "name_4: " << name_4 << std::endl;
    std::cout << "name_4.size: " << name_4.size() << std::endl;

    // 生成一个string对象，该对象包含5个u字符
    std::string name_5{
        5,
        'u'};  // 但是使用{}初始化的话，会将{}里的东西当作初始化列表，5会被当成一个字符，不是字符5，是5在ASCII对应的字符
    std::cout << "name_5: " << name_5 << std::endl;
    std::cout << "name_5.size: " << name_5.size() << std::endl;
    std::string name_6(5, 'u');
    std::cout << "name_6: " << name_6 << std::endl;
    std::cout << "name_6.size: " << name_6.size() << std::endl;

    // 通过C风格字符串的起始地址和其他有效地址范围进行构造
    const char* ptr_name_7{"wangshuai"};
    std::string name_7{ptr_name_7, ptr_name_7 + 5};
    std::cout << "name_7: " << name_7 << std::endl;
    std::cout << "name_7.size: " << name_7.size() << std::endl;

    // 通过已存在的string对象中的迭代器进行构造一个新的string对象
    // 范围是半开区间[begin,end)
    std::string name_8{name_1.begin(), name_1.end()};
    std::cout << "name_8: " << name_8 << std::endl;
    std::cout << "name_8.size: " << name_8.size() << std::endl;
}

// string类的常见操作
void test1() {
    auto show = [](const std::string& name) {
        std::cout << "name: " << name << std::endl;
        std::cout << "name.size: " << name.size() << std::endl;
    };
    std::string name{"bitofux"};

    // string对象的size: 有效字符
    std::cout << "name.size: " << name.size() << std::endl;
    std::cout << "name.length: " << name.length() << std::endl;

    // 返回string中内部的字符动态数组的指针
    const char* ptr{name.c_str()};
    std::cout << (void*)ptr << std::endl;

    // 判断string对象是否为空
    if (name.empty()) {
        std::cout << "TRUE\n";
    } else {
        std::cout << "FALSE\n";
    }

    // 末尾添加一个字符
    name.push_back('a');
    show(name);

    // 末尾追加count个字符
    name.append(5, 'h');
    show(name);

    // 末尾追加一个string对象
    std::string name_1{name.begin(), name.end() - 3};
    name.append(name_1);
    show(name);

    // 添加C风格字符串
    name.append("hello world");
    show(name);

    // 在string对象中查找单个字符 返回这个字符的下标
    // 若没找到则返回npos 默认从0下标开始查找
    std::string::size_type n = name.find('z', 0);
    if (n == std::string::npos) {
        std::cout << "n == npos" << std::endl;
    } else {
        std::cout << "n: " << n << std::endl;
    }

    // 在string对象中查找C风格字符串的n个字符
    n = name.find("xahhh", 5);
    std::cout << "n: " << n << std::endl;
}

// string类的遍历
void test2() {
    std::string name{"bitofux"};

    // 1. 使用指针遍历
    auto ptr{name.data()};

    for (int i = 0; i < name.size(); ++i) {
        std::cout << ptr[i] << " ";
    }
    std::cout << std::endl;

    // 增强for循环
    for (const auto& var : name) {
        std::cout << var << " ";
    }
    std::cout << std::endl;

    // 使用迭代器
    for (auto it{name.begin()}; it != name.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

int main() {
    // test();
    // test1();
    test2();

    return 0;
}
