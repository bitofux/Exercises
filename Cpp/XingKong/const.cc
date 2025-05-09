#include <iostream>
using std::cout;
using std::endl;

// 符号常量
#define MAX 100
// const修饰变量
void test() {

  // 普通变量可以不初始化,后续可以修改
  int a;
  a = 10;
  cout << "a = " << a << endl;

  // const修饰的变量不可以不初始化，且不可以修改
  //  const int b;//error
  const int b = 20;
  // b = 30;//error
  cout << "b = " << b << endl;

  // 符号常量
  cout << "MAX = " << MAX << endl;
}

// const修饰指针
void test1() {

  // 常量指针:指向的对象不可修改,指针本身的值不可改变
  int a = 10, b = 20;
  const int *ptr = &a;
  cout << "before changing ptr: " << ptr << endl;
  ptr = &b; // ptr的值可以修改
  cout << "after changing ptr: " << ptr << endl;
  //*ptr = 2;//指向的对象不可修改

  // 指针常量:指针本身的值可以改变，指向对象的值不可改变
  int c = 1, d = 3;
  int *const ptr1 = &c;
  cout << "before changing *ptr1: " << *ptr1 << endl;
  // ptr1 = &d;//指针本身的值不可更改
  *ptr1 = 40; // 指向的对象值可以更改
  cout << "after changing *ptr1: " << *ptr1 << endl;
}
int main() {

  // test();
  // test1();
  return 0;
}
