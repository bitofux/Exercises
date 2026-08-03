/****************************************************
 * @file    cpp_string.cc
 * @brief   C++ Strings
 * @author  bitofux
 * @date    2025-10-12
 ****************************************************/
#include <iostream>
#include <string>  // for std::string
//

// String的初始化方法
void test1() {
    // 1. 默认构造(空字符串)
    std::string s1;
    std::cout << "s1: " << s1 << "\n";

    // 2. 使用C风格的字符串字面量
    std::string s2{"bitofux"};
    std::cout << "s2: " << s2 << "\n";

    /*3.
     * 使用已经存在的string对象去构造
     * 调用拷贝构造函数创建一个与现有字符串  相同的新
     * 字符串
     */
    std::string s3{s2};
    std::cout << "s3: " << s3 << "\n";

    /*4.
     * 还可以从另外一个字符串的子串
     * 创建一个新的字符串，需要指定
     * 索引和长度
     */
    std::string s4{s2, 1, 3};
    std::cout << "s4: " << s4 << "\n";

    /* 5.
     * 还可以通过重复一个字符
     * 多次创建一个字符串
     */
    std::string s5(5, 'a');
    std::cout << "s5: " << s5 << "\n";

    // 6. 使用初始化列表创建string对象
    std::string s6{'a', 'b'};
    std::cout << "s6: " << s6 << "\n";
}

void test2() {
    std::string name = "bitofux";

    // 判断是否为空
    std::cout << "is empty: " << name.empty() << "\n";

    // 获取字符串长度
    size_t len = name.length();
    std::cout << "len: " << name << "\n";

    // 提取子串"tofu"
    std::cout << "substr(2,4): " << name.substr(2, 4) << "\n";

    // 两个字符串拼接
    std::string age = "'s age is 20!";
    name += age;
    std::cout << "name += age: " << name << "\n";
    name.append(" I say Hello");
    std::cout << "name: " << name << "\n";

    // 清空string
    name.clear();
    std::cout << "after clear,name: " << name << "\n";
}
int main() {
    // 创建一个C++ string
    std::string name = "bitofux";

    std::cout << name << std::endl;
    test1();
    // test2();
    return 0;
}
