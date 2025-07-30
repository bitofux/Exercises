// write output(formatted) to a file, using <<

#include <iostream>
#include <fstream>
#include <string>
int main() {
    // 声明一些要写入文件的变量
    char ch{'z'};
    int i{77};
    short s{20};
    float f{20.22f};
    double d{22.22};
    std::string str1{"Hello"};
    std::string str2{"File"};

    // 打开文件
    std::ofstream outfile{"File_1.txt", std::ios::out};

    // 写入数据
    outfile << ch << i << ' ' << s << ' ' << f << ' ' << d << ' ' << str1 << ' ' << str2;

    // 关闭文件
    outfile.close();

    // 追加模式再次打开文件
    std::ofstream outfile1{"File_1.txt", std::ios::out | std::ios::app};

    // 写入数据
    outfile1 << "Hello,Bitofux";

    // 关闭文件
    outfile1.close();

    // 再次打开文件,若存在则清空
    std::ofstream outfile2{"File_1.txt", std::ios::out | std::ios::trunc};

    // 写入数据
    outfile2 << "Hello,World!";

    // 关闭文件
    outfile2.close();

    // 再次以只读模式打开,将文件指针定位到文件末尾
    std::ifstream infile{"File_1.txt", std::ios::in | std::ios::ate};

    // 获取文件数据大小
    int length = infile.tellg();
    std::cout << "length: " << length << "\n";
    // 设置文件指针到文件开头
    infile.seekg(-length, std::ios::cur);
    char buf[length / 2];

    while (infile >> buf) {
        std::cout << buf << std::endl;
    }
    std::cout << "infile流对象的状态: " << infile.rdstate() << std::endl;
    return 0;
}
