#include <iostream>

int main () {
  using std::cout;
  using std::endl;

  int x = 10;
  cout << &x << '\n';//输出x的地址(这个位置是存储在RAM)
  
  int *ptr = &x;
  cout << ptr << '\n';
  *ptr = 5;//利用解引用操作符对ptr指向的对象进行写操作
  int y = *ptr;//利用解引用操作符对ptr指向的对象进行读操作
  cout << "x = " << x << "\ny = " << y << "\n";

  ptr = nullptr;
  //不可以使用解引用操作符*对值为nullptr的指针变量进行读写
  // cout << "*ptr = " << *ptr << endl;//error
  // *ptr = 5;//error

  return 0;
}
