#include <fstream>
#include <iostream>

int main() {
    // 打开一个文件
    std::ofstream ofs1{"test.txt", std::ios::out};

    if (!ofs1) {
        std::cerr << "打开文件失败" << std::endl;
    }

    ofs1 << "hello world!" << 12 << "woaini";

    if (!ofs1) {
        std::cerr << "输出失败" << std::endl;
    }
}
