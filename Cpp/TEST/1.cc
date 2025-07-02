#include <iostream>
using std::cout;
using std::endl;

// 顶层const/volatile
void test0() {
  const int a{20};
  auto auto_a{a}; // -> T = int
  volatile double d{20.22};
  auto auto_d{d}; // -> T = double
}
// 左值/右值引用
void test1() {
  // 左值引用
  int a{20};
  int &ref_a{a};
  auto auto_a{ref_a}; // -> T = int
  // 右值引用
  int &&rref{20};
  auto &auto_b{rref}; // -> T = int
}
// 数组退化为指针 但不会改变其底层修饰
void test3() {
  // 1. 无底层修饰
  int arr[] = {1, 2, 3, 4, 5};
  auto auto_arr{arr}; //-> T = int*
  // 可以修改数组元素
  *(auto_arr + 1) = 20;
  cout << "arr[1]: " << arr[1] << endl;
  // 2. 有底层修饰
  const float frr[] = {1.1, 2.2, 3.3, 4.4};
  auto auto_frr{frr}; // -> T = const float*
  // *(auto_frr + 1) = 20.22;//不可修改数组元素
}
// 函数退化为指针
void test4() {
  auto auto_test0{test0};
  // 利用函数指针调用test0
  auto_test0();
}
// 保留底层修饰
void test5() {
  int a{20};
  const int *ptr{&a};
  auto auto_ptr{ptr};
  // 解引用auto_ptr不可以修改a;
  //  *auto_ptr  = 30;//error,因为auto_ptr的类型是const int*
}
// 保留cv-qualifier的成员指针
void test6() {
  struct A {
    A():cm_{20}{}
    int m_;
    const int cm_;
  };
  A a;
  a.m_ = 10;
  const int A::*const ptr = &A::cm_;
  auto x = &A::m_; //-> T = int A::*
  auto y = ptr;    // -> T = const int A::*
                // 去掉顶层const，也就是修饰指针变量ptr本身的const
  std::cout << "a.*x: " << a.*x << '\n'; 
  std::cout << "a.*y: " << a.*y << '\n'; 
  static_assert(std::is_same<decltype(x), int A::*>::value, "OK");
  static_assert(std::is_same<decltype(y), const int A::*>::value, "OK");
}
int main() {
  // test0();
  // test1();
  // test3();
  // test4();
  test6();
}
