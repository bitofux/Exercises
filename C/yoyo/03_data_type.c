#include <stdio.h>
#include <stdbool.h>

/*
 * 字面量:
 * 1.整型(type is int): 10 20 -1
 * 2.浮点数(type is double):3.14 -3.14 0.314E+1
 * 3.字符(type is char): 'a' 'A'
 * 4.字符串(类型是分情况):"A" "bitofux"
 * 5.符号常量:宏定义,比如EXIT_SUCCESS*/

/*
 * 变量:其值在程序运行中随时可能发生变化的量(在一个定义未被初始化或被赋值之前不要使用,因为不同的编译器在不同的平台结果不同,特别是指向某种类型的指针类型的变量)
 * */

/*
 * 基本数据类型:
 * 1.整数类型([signed short signed int signed long][unsigned short unsigned int unsigned long])int一定不能比short所占的字节少,long一定不能比int所占的字节少.并不是short < int < long
 * 2.浮点数类型(float double long double)
 * 3.字符型(char)*/

/*
 * 组合数据类型:
 * 1.数组
 * 2.结构体
 * 3.联合体*/

/*其他类型:
 * 1.枚举(取值在有限范围内 -> 增强代码可读性 使得代码更美观)
 *  枚举类型中所有的成员组成一个枚举列表
 *  第一个成员的值默认是0,随后后一个成员的值比前一个成员+1
 *  但是可以通过赋值改变,比如一个枚举列表是{RED,GREEN = 12,WHITE}
 *  那么RED的默认值还是0,但是GREEN的值是12,且WHITE的值是13
 *
 * 2.指针(pointer to type)
 * */
void enumType(){
  //函数内定义一个枚举类型
  typedef enum Color {RED,GREEN,WHITE} color;
  //利用color定义一个变量,并使用一个枚举列表中的其中一个枚举成员初始化或者赋值
  color var_color = RED;
  printf("var_color is %d\n",var_color);
}
void baseType(){
  int a = 'a';
  printf("a is %d\n",a);
  const char* string = "hello";
  printf("string is %s\n",string);
  short int si = 10;
  printf("si is %hd\n",si);
  double d = 3.14;//double
  printf("d is %lf\n",d);
  float f = 3.1f;//float
  printf("f is %f\n",f);
  bool var = true ;
  printf("var is %d\n",var);
}
int main () {

  enumType();
  baseType();//函数调用
  return 0;
}
