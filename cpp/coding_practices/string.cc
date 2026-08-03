/*
 * PROJECT : EXERCISES
 * FILE    : string.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-04-09
 * BRIEF   : string类的接口测试
 */
#include <iostream>
#include <string>

using namespace std;

int main() {
    string name = "bi#to;fu#tx";

    // 获取tofu这个子字符串
    std::cout << "bitofux->tofu: " << name.substr(2, 5);

    // 查找#;字符集中第一个出现的字符的所在的位置
    std::cout << "pos1: " << name.find_first_of("#;") << "\n";

    // 查找不在#;字符集中第一个出现的字符所在的位置
    std::cout << "pos2: " << name.find_first_not_of("#;") << "\n";

    // 查找一个字符串所在的位置
    std::cout << "pos3: " << name.find("#t") << "\n";

    // 查找一个字符所在的位置
    std::cout << "pos4: " << name.find(';') << "\n";

    // 查找一个字符串所在的最后一个位置
    std::cout << "pos5: " << name.rfind("#t") << "\n";

    // 查找一个字符所在的最后一个位置
    std::cout << "pos6: " << name.rfind('t') << "\n";

    string str{"name"}, str1{"aname"};
    std::cout << "str compare str1: " << str.compare(str1) << "\n";

    string str2 {"#我爱你"};
    str2 = str2.substr(0,str2.find_first_of("#;"));
    std::cout << str2 << "\n";
    return 0;
}
