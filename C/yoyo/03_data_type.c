#include <stdio.h>
#include <stdbool.h>

/*
 * 字面量:
 * 1.整型(type is int): 10 20 -1
 * 2.浮点数(type is double):3.14 -3.14 0.314E+1
 * 3.字符(type is char): 'a' 'A'
 * 4.字符串(类型是分情况):"A" "bitofux"*/

/*
 * 基本数据类型:
 * 1.整数类型
 * 2.浮点数类型
 * 3.字符型*/
void baseType(){
  int a = 'a';
  "hello";
  10;
  3.14;//double
  3.1f;//float
  bool var = true ;
  printf("a is %d\n",a);
}
int main () {

  baseType();//函数调用
  return 0;
}
