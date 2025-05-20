#include <iostream>
using std::cout;
using std::endl;

// 引用
// 引用的对象不能是以结束的函数局部变量
// 引用的对象最好不是已结束函数中申请的堆对象
// 可以是静态对象，也可以是全局对象
void test() {

  int a = 10;

  int &ref = a;
  ref = 30;

  cout << "a = " << a << " &a = " << &a << endl;
  cout << "ref = " << ref << " &ref = " << &ref << endl;
}

int main() {

  test();

  return 0;
}
