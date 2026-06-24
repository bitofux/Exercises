/*
 * PROJECT : DAY8
 * FILE    : 4.ofstream.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-06-13
 * BRIEF   : 文件输出流
 */

#include <iostream>
#include <fstream>

using std::cout;
using std::endl;
using std::ofstream;

void test() {
    std::ofstream ofs{"data_out.txt"};

    if (!ofs.is_open()) {
        std::cerr << "is_open failed\n";
        return;
    }

    std::string name{"bi t ofux"};
    // 格式化写入
    ofs << name;

    // 获取文本文件大小
    ofs.seekp(0, std::ios::end);
    std::cout << "size: " << ofs.tellp() << std::endl;

    // write写入数据

    int num = 200000;
    ofs.write((const char*)&num, sizeof(num));

    ofs.close();

    // 重新打开
    std::ofstream ofs1{"data_out.txt", std::ios::ate};

    ofs1.seekp(0, std::ios::end);
    std::cout << ofs1.tellp() << std::endl;
}
int main() {
    test();

    return 0;
}
