/*
 * PROJECT : EXERCISES
 * FILE    : test_file.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-06-15
 * BRIEF   :
 */
#include <ios>
#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream ifs;
    ifs.open("a.txt", std::ios::in);

    // 输出文件字符个数
    // ifs.seekg(0,std::ios::end);
    // std::cout << "size: " << ifs.tellg() << std::endl;
#if 1
    // 非格式化读取
    char buf[2] = {0};
    ifs.read(buf, 2);

    std::string data{buf, buf + 2};

    std::cout << "size: " << data.size() << std::endl;

    std::cout << data.find('\n') << std::endl;

    for (auto& val : data) {
        std::cout << "val: " << val << std::endl;
        if (val == '\0') {
            std::cout << "yes\n";
        }
    }
#endif
}
