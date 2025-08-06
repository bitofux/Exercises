#include <iostream>
#include <fstream>
#include <iomanip>

#pragma pack(1)
typedef struct Person {
    char name[10];
    int age;
} person;
#pragma pack()

namespace tofu {
void printStreamState(std::ifstream& fin) {
    std::cout << " [eof:" << fin.eof() << " fail:" << fin.fail() << " bad:" << fin.bad()
              << " good:" << fin.good() << "]";
}

void printPerson(const person& p) { std::cout << "Name: " << p.name << " ,age: " << p.age << '\n'; }
}  // namespace tofu

int main() {
    std::ifstream fin{"./people.bin", std::ios_base::binary | std::ios_base::in};
    if (!fin) {
        std::cerr << "打开文件失败!\n";
        return 1;
    }

    int index = 0;
    while (true) {
        person p;
        fin.read(reinterpret_cast<char*>(&p), sizeof(p));
        // 获取读取个数
        std::streamsize count = fin.gcount();
        std::cout << "第 " << ++index << " 次读取，尝试读取 " << sizeof p << " 字节，实际读取了 "
                  << count << " 字节";
        tofu::printStreamState(fin);
        std::cout << '\n';

        if (count == 0) break;  // 正常退出

        if (static_cast<size_t>(count) < sizeof(p)) {
            std::cerr << "结构体数据不完整,停止处理\n";
            break;
        }

        tofu::printPerson(p);

        if (fin.eof()) break;  // 可以提前结束
    }

    return 0;
}
