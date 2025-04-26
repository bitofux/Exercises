#include <iostream>
using std::cout;
using std::endl;

//引用
void test() {

  int a = 10;

  int& ref = a;
  ref = 30;

  cout << "a = " << a << " &a = " << &a <<  endl;
  cout << "ref = " << ref << " &ref = " << &ref << endl;
}

int main () {

  test();

  return 0;
}
