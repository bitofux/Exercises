// 编写一个程序，使用malloc动态分配一个整型数组的空间，允许用户输入数组的大小(不超过100)，然后输入数组的元素值，并打印数组的//内容，最后使用free释放内存

#include <cstdlib>
#include <iostream>

int main() {
    std::cout << "输入数组的大小(不超过100): ";
    int size = 0;
    std::cin >> size;
    if (size <= 0) {
        std::cout << "input error\n";
        return 1;
    }

    std::cout << "size = " << size << std::endl;
    // 使用malloc分配size大小的整型数组
    int* ptr = static_cast<int*>(malloc(size * sizeof(*ptr)));
    if (ptr == nullptr) {
        std::cerr << "分配内存失败\n";
        return 1;
    }

    // 用户输入数组元素的值
    std::cout << "输入各个元素的值(按元素顺序输入)\n";
    for (int i = 0; i < size; i++) {
        std::cout << "输入第" << i + 1 << "个元素的值: ";
        std::cin >> ptr[i];
    }

    // 打印数组中元素的值
    for (int i = 0; i < size; i++) {
        std::cout << ptr[i] << ' ';
    }
    std::cout << '\n';

    free(ptr);

    return 0;
}
