/*编写一个程序，定义一个整型数组arr，包含5个元素{1, 2, 3, 4,
 * 5}，通过指针遍历并打印数组中的所有元素*/

#include <iostream>

int main() {
    int arr[5] = {1, 2, 3, 4, 5};

    for (int i = 0; i < 5; i++) {
        std::cout << "arr[" << i << "]: " << *(arr + i) << '\n';
    }

    return 0;
}
