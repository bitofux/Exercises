//编写一个程序，定义一个整型数组arr，包含10个元素，使用memset将数组的所有元素初始化为0，并打印数组的内容以验证
#include <cstddef>
#include <cstring>
#include <iostream>

int main() {
  int arr[] = {1,2,3,4,5,6,7,8,9,10};
  auto len = sizeof(arr) / sizeof(arr[0]);

  memset(arr, 0x00,sizeof arr);

  for (size_t i = 0;i < len;i++) {
    std::cout << "arr[" << i << "]: " << arr[i] << "\n";
  }

  return 0;
}
