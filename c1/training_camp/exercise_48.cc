// 编写一个程序,首先使用malloc分配一个整型数组的空间，并填充一些初始值。然后使用realloc增加数组的大小
// 并再次填充新分配的部分，最后打印出整个数组的内容，最后使用free释放内存

#include <cstdlib>
#include <iostream>

int main() {
    int* ptr = static_cast<int*>(malloc(sizeof(*ptr) * 5));
    if (!ptr) {
        std::cerr << "分配内存失败\n";
        return 1;
    }

    for (int i = 0; i < 5; i++) {
        ptr[i] = i * 2;
    }

    int* tmp = static_cast<int*>(realloc(ptr, sizeof(*tmp) * 10));
    if (tmp == nullptr) {
        free(ptr);
        ptr = nullptr;
    } else {
        ptr = tmp;
    }

    for (int i = 0; i < 5; i++) {
        ptr[i + 5] = ptr[i] * 2;
    }

    for (int i = 0; i < 10; i++) {
        std::cout << ptr[i] << ' ';
    }
    std::cout << '\n';

    free(ptr);

    return 0;
}
