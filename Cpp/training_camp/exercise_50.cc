// 编写一个程序，包含两个整数。第一个函数使用栈内存(局部变量)存储并打印一个整数数组;第二个函数使用堆内存动态分配并打印
// 一个整数数组，然后打印并释放内存。通过两个函数的调用展示栈内存和堆内存在使用上的区别。
#include <cstdlib>
#include <iostream>

void showStack() {
    int arr[5] = {1, 2, 3, 4, 5};
    for (auto& ref : arr) {
        std::cout << ref << ' '; 
    }
    std::cout << '\n';
}

void showHeap() {
    int* arr = reinterpret_cast<int*>(malloc(sizeof(*arr) * 5));
    if (arr == NULL) {
        std::cerr << "内存分配失败\n";
        return;
    }

    std::cout << "输入5个整数\n";
    for (int i = 0; i < 5; i++) {
        std::cout << "输入第" << i << "个整数: ";
        std::cin >> arr[i];
    }

    for (int i = 0; i < 5; i++) {
        std::cout << arr[i] << ' ';
    }
    std::cout << '\n';

    free(arr);
}
int main() {
    // 栈
    showStack();

    // 堆
    showHeap();

    return 0;
}
