/****************************************************
 * @file    list_dir.cc
 * @brief   使用filesystem列出目录项
 * @author  bitofux
 * @date    2025-10-23
 ****************************************************/
#include <algorithm>
#include <iostream>
#include <filesystem>
#include <string_view>
#include <vector>
namespace fs = std::filesystem;

void list_directory(std::string_view file) {
    fs::path currentPath{file};
    // 输出当前路径的字符串
    std::cout << "currentPath: " << currentPath.string() << "\n";
    // 使用fs::director_iterator这个类型定义两个对象
    // 分别表示路径下的起始位置和结束位置
    // 迭代器指向directory_entry对象，可以使用其访问
    // 每个目录项的详细信息

    // 使用当前路径对象进行初始化获取起始位置
    fs::directory_iterator begin{currentPath};
    // 使用空参数进行初始化获取最后一个目录项的下一个位置
    fs::directory_iterator end{};

    while (begin != end) {
        auto de = *begin;
        if (de.is_directory()) {
            std::cout << "directory: " << de.path().string() << "\n";
        } else {
            std::cout << "filename: " << de.path().filename().string() << "\n";
        }
        ++begin;
    }
}
void list_directory_entry(std::string_view file) {
    fs::path currentPath{file};
    if (!fs::exists(currentPath)) {
        std::cerr << "currentPath is invalid\n";
        return;
    }
    // 基于范围的for循环
    for (const auto& dir_entry : fs::directory_iterator{currentPath}) {
        // 获取当前目录项实体的类型枚举值
        // 使用switch进行枚举，判断是否是目录或者普通文件
        // dir_entry.status() -> file_status
        // dir_entry.status().type() -> file_type
        switch (dir_entry.status().type()) {
            case fs::file_type::regular: {
                std::cout << "filename: " << dir_entry.path().filename().string()
                          << " file size: " << dir_entry.file_size() << "\n";
                break;
            }
            case fs::file_type::directory: {
                std::cout << "DIR: " << fs::relative(dir_entry.path(), currentPath).string()
                          << "\n";
                break;
            }
        }
    }
}
void use_partition(std::string_view file) {
    fs::path currentPath{file};
    if (!fs::exists(currentPath)) {
        std::cerr << "currentPath is invalid\n";
        return;
    }
    std::vector<fs::directory_entry> entrys{20};
    for (const auto& dir_entry : fs::directory_iterator{currentPath}) {
        entrys.push_back(dir_entry);
    }

    std::partition(entrys.begin(), entrys.end(),
                   [](const fs::directory_entry& de) { return de.is_directory(); });

    for (const auto& elemnt : entrys) {
        switch (elemnt.status().type()) {
            case fs::file_type::regular: {
                std::cout << "filename: " << elemnt.path().filename().string()
                          << " file size: " << elemnt.file_size() << "\n";
                break;
            }
            case fs::file_type::directory: {
                std::cout << "DIR: " << fs::relative(elemnt.path(), currentPath).string() << "\n";
                break;
            }
        }
    }
}
int main() {
    // list_directory("./");
    // list_directory_entry("./");
    use_partition("./");
    return 0;
}
