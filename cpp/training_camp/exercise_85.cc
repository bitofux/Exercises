// 编写一个C++程序，定义一个整型数组和字符指针
// 使用reinterpret_cast将整型数组的指针转换为字符指针
// 并尝试通过字符指针访问数组的前几个字节
// 以展示不同内存内容的不同解释方式
#include <iostream>

int main() {
    int arr[5] = {23020, 200, 300, 400, 500};

    char* ptr{reinterpret_cast<char*>(&arr[0])};

    std::cout << *ptr << '\n';
    std::cout << *(ptr + 1) << '\n';

    return 0;
}
