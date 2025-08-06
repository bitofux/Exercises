#include <fstream>
#include <iostream>
#pragma pack(1)
typedef struct Persoon {
    char name[10];
    int age;
} person;
#pragma pack()

int main() {
    // 二进制模式打开people.bin文件
    std::ofstream fout{"./people.bin", std::ios_base::binary | std::ios_base::trunc};
    if (!fout) {
        std::cerr << "打开文件失败!\n";
    }

    // 创建一个person类型数组
    person p_arr[4] = {{"Alice", 30}, {"Bob", 20}, {"Charlie", 27}, {"Diana", 18}};

    // 前三个数组元素写满数据到文件
    for (int i = 0; i < 3; i++) {
        fout.write(reinterpret_cast<char*>(&p_arr[i]), sizeof(p_arr[i]));
    }

    // 最后一个数组元素只写一部分,前8个字节
    fout.write(reinterpret_cast<char*>(&p_arr[3]), sizeof(p_arr[3]));

    return 0;
}
