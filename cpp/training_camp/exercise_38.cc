/*编写一个C++程序，要求从文件中读取一系列整数（每个整数占一行），计算这些整数的平均值，并将结果写入另一个文件中。*/

#include <iostream>
#include <fstream>

int main() {
    // 保存读取整数的变量
    int number = 0;
    // 保存读取整数的个数
    int count = 0;
    // 保存所有整数的和
    int sum = 0;
    // 打开一个包含一系列整数的文件
    std::ifstream ifs;
    ifs.open("./file38_1.txt", std::ios_base::in);
    if (ifs.is_open()) {
        while (ifs >> number) {
            sum += number;
            count++;
        }

        // 将平均值写入另外一个文件
        std::ofstream ofs;
        ofs.open("./file38_2.txt", std::ios_base::out);
        if (ofs.is_open()) {
            ofs << sum / count;
        } else {
            std::cerr << "打开文件失败!" << '\n';
        }
        ofs.close();
    } else {
        std::cerr << "打开文件失败!" << '\n';
    }

    ifs.close();

    return 0;
}
