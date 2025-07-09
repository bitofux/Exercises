//编写一个程序，定义两个整型数组src和dest,其中src包含5个元素{1,2,3,4,5},使用memcpy将src数组的内容复制到dest数组中,并打印dest数组的内容
#include <cstddef>
#include <cstring>
#include <iostream>

int main() {
  int src[] = {1,2,3,4,5};
  int dest[5] = {0};

  memcpy(dest, src, sizeof(src));

  for (size_t i = 0;i < sizeof(dest) / sizeof(int);i++) {
    std::cout << "dest[" << i << "]: " << dest[i] << "\n";
  }

  return 0;
}
