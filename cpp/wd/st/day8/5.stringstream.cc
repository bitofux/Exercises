/*
 * PROJECT : DAY8
 * FILE    : 5.stringstream.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-06-15
 * BRIEF   : 字符串流
 */
#include <filesystem>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using std::cout;
using std::endl;
using std::ifstream;
using std::istringstream;
using std::ostringstream;

// 测试一下字符串输入流对象：字符串数据到其他类型的转换
void test() {
    istringstream istr{"12345 3.14 a"};
    int number = 0;
    double dou = 0.0;
    char ch = '\0';

    // 从字符串输入流对象中读取格式化数据
    istr >> number >> dou >> ch;

    // 输出查看数据
    cout << "number: " << number << "\ndou: " << dou << "\nch: " << ch << std::endl;
}

// 读取配置文件
void read_config() {
    // 打开配置文件
    ifstream ifs{"db.config"};
    if (!ifs.is_open()) {
        std::cerr << "ifs open files error" << std::endl;
        return;
    }

    // 循环读取文件中的每一行
    std::string line{};
    while (std::getline(ifs, line)) {
        // 定义一个字符串输入流对象，将每一行的数据先保存到字符串输入流对象
        istringstream istr{line};
        // 定义key和value
        std::string key, value;

        // 从字符串输入流对象读取格式化数据
        istr >> key >> value;

        // 输出Key和value的值
        std::cout << key << ": " << value << "\n";
    }
}

// 读取配置文件 '='
void read_config_equal() {
    // 打开配置文件
    ifstream ifs{"db.config"};
    if (!ifs.is_open()) {
        std::cerr << "ifs open file error\n";
        return;
    }

    // 循环读取文件内的每一行数据
    std::string line{};
    while (std::getline(ifs, line)) {
        // 处理line中的'='字符，先找到其下标，利用下标将其值设置为空格字符
        auto index = line.find('=');
        if (index != line.npos) {
            line[index] = ' ';
        }

        // 创建一个字符串输入流对象
        istringstream istr{line};

        // 定义key和value
        std::string key, value;

        // 从字符串输入流对象中格式化读取数据
        istr >> key >> value;

        std::cout << key << " = " << value << std::endl;
    }
}

int main() {
    // test();
    // read_config();
    read_config_equal();
    return 0;
}
