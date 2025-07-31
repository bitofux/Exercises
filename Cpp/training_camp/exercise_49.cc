// 编写一个程序，动态分配一个整型数组的内存空间，用于存储用户输入的5个整数，然后遍历并打印
// 这些整数。最后，释放分配的内存

#include <cstdlib>
#include <iostream>

int main() {
    int* ptr = reinterpret_cast<int*>(malloc(sizeof(*ptr) * 5));
    if (ptr == NULL) {
        std::cerr << "内存分配失败\n";
        return 1;
    }

    std::cout << "输入5个整数\n";
    for (int i = 0; i < 5; i++) {
        std::cout << "输入第" << (i + 1) << "个整数: ";
        std::cin >> ptr[i];
    }

    for (int i = 0; i < 5; i++) {
        std::cout << ptr[i] << ' ';
    }
    std::cout << '\n';

    free(ptr);

    return 0;
}
