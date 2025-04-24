#include <cstdlib>
#include <cstring>
#include <iostream>
using std::cout;
using std::endl;

// malloc申请的内存没有被初始化
// void test() {
//
//   int *ptr = static_cast<int *>(malloc(sizeof(int)));
//   // 使用字节级别的内存操作函数将4个字节中的每个字节都设置为0
//   memset((void *)ptr, 0, sizeof(int));
//   cout << "*ptr = " << *ptr << endl;
//   // 释放这块内存
//   free(ptr);
// }

// 使用new运算符申请内存的同时可以初始化
void test1() {

  int *ptr = new int{10};
  cout << "*ptr = " << *ptr << endl;
  // 释放内存
  delete ptr;

  // 申请一块大小相同且连续的内存空间 -- 数组
  char *ptr1 = new char[2]{'a', 'b'};

  delete[] ptr1;
}

int main() {

  // test();
  test1();
  return 0;
}
