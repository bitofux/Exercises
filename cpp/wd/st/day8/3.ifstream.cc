/*
 * PROJECT : DAY8
 * FILE    : 3.ifstream.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-06-13
 * BRIEF   : 文件输入流
 */
#include <iostream>
#include <fstream>

using std::cout;
using std::endl;
using std::ifstream;

// 读取一个文件的全部内容
void test() {
    // 打开一个文件
    ifstream ifs{"data.txt"};

    // 检查打开的状态
    if (!ifs.is_open()) {
        std::cout << "failed open file" << std::endl;
    }

    // 将读取的游标放到文件末尾
    ifs.seekg(0, std::ios::end);
    // 获取游标位置，这个数值就是文件中字符的总个数
    auto count = ifs.tellg();
    std::cout << "count: " << count << std::endl;

    // 将游标调整到开头
    ifs.seekg(0, std::ios::beg);

    char buf[1024] = {0};
    ifs.read(buf, count);

    std::string content{buf};

    // 检查一下末尾有没有'\n'
    std::string::size_type n = content.find_first_of('\n');
    std::cout << "n: " << n << std::endl;

    // 输出'\n'的个数
    int cn = 0;
    for (auto& ch : content) {
        if (ch == '\n') {
            ++cn;
        }
    }

    // 输出'\n'所在的下标
    for (int i = 0; i < content.size(); ++i) {
        if (content.at(i) == '\n') {
            std::cout << "i: " << i << std::endl;
        }
    }

    std::cout << "cn: " << cn << std::endl;

    std::cout << "content: " << content;
}

int main() {
    test();

    return 0;
}
