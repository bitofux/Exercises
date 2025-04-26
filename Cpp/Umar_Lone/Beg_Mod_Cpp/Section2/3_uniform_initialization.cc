#include <iostream>

int main() {
  using std::cout;
  using std::endl;
  int a1;     // 未初始化
  int a2 = 0; // 拷贝初始化
  int a3(5);  // 直接初始化
  std::string s1;
  std::string s2("C++"); // 直接初始化

  char d1[8]; // 未初始化
  char d2[8] = {'\0'};
  char d3[8] = {'a', 'b', 'c', 'd'};
  char d4[8] = {"abcd"};
  char d5[8] = "abcd"; // 聚合初始化，但其实这也是一种拷贝初始化

  int b1{}; // 值初始化，且默认初始化为0
  float f1{};
  bool bool_b1{};
  cout << "f1 = " << f1 << endl;
  cout << "bool_b1 = " << bool_b1 << endl;
  cout << "b1 = " << b1 << endl;
  // int b2();//error 错误的解析,会被识别为一个参数为为空，返回值为int的函数声明
  int b3{5}; // 直接初始化

  int b4 =
      0; // 这称为拷贝初始化，应该避免这种，特别是在初始化用户定义类型中，如类、结构体

  char e1[8]{}; // 值初始化，且默认初始化为'\0'
  // 同时也适用于在堆上创建
  cout << "e1[0] = " << e1[0] << endl;
  char *p1 = new char{};
  cout << "*p1 = " << *p1 << endl;

  char e2[8]{"hello"};
  cout << "e2 = " << e2 << endl;
  char *p2 = new char[8]{"hello"};
  cout << "p2 = " << p2 << endl;


  //统一初始化禁止
}
/*
对于原始类型，使用赋值运算符初始化是简单明了的，特别针对于用户定义类型，要尽量使用uniform initialization

上述说的统一初始化的几种分类:
1.value initialization => T obj{};
2.direction initialization => T obj{v};
3.copy initialization => T obj = v;//避免使用
使用统一初始化的好处:
1.它强制初始化
2.可以对数组类型使用直接初始化
3.防止窄化转换(精度收缩转换) -> 指的是一种较宽范围或精度高的类型转换为较窄范围或精度低的类型。这种转换可能会导致数据丢失或精度降低
  浮点数到整数的转换 -> 小数部分会被截断
  大范围整数到小范围整数
  long long big_number = 1'000'000'000'000;
  int small_number = static_cast<int>(big_number);数值被截断
  容量更大的容器到更小容器
  std::vector<long>转换为std::vector<int>
  而使用统一初始化可以避免这个问题
*/
