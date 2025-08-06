/*编写一个函数，该函数接收一个整型数组和数组的长度作为参数，通过指针参数修改数组中的元素，使所有元素的值加倍*/

#include <cstddef>
#include <iostream>

namespace {
void modify(int* arr, size_t len) {
    for (size_t i = 0; i < len; i++) {
        *(arr + i) *= 2;
    }
}
}  // namespace
int main() {
    int arr[6] = {1, 2, 3, 4, 5, 6};
    modify(arr, sizeof(arr) / sizeof(arr[0]));

    return 0;
}
