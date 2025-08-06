/*编写一个C++程序，要求输出一个表格，表格包含三列：序号（从1开始）、用户输入的名字（字符串）、和该名字的长度（整数）。表格的每列都应该右对齐，并且序号和名字长度列的宽度分别为4和10*/

#include <iomanip>
#include <iostream>
#include <string>
struct Person {
    std::string name_;
    unsigned short name_length_;
};
int main() {
    // 定义一个Person数组
    Person p_arr[3];

    // 要求用户输入自己的名称,并计算名称的长度
    for (int i = 0; i < 3; i++) {
        std::cout << "输入第" << i + 1 << "个用户的名称: ";
        std::cin >> p_arr[i].name_;
        p_arr[i].name_length_ = strlen(p_arr[i].name_.c_str());
    }

    // 按表格输出用户信息
    for (int i = 0; i < 3; i++) {
        std::cout << std::setw(4) << i + 1 << std::setw(15) << p_arr[i].name_ << std::setw(10)
                  << p_arr[i].name_length_;
        std::cout << std::endl;
    }

    return 0;
}
