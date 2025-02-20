#include <stdbool.h>
#include <stdio.h>
/*隐式类型转换:当操作符两边的操作数类型不同时,编译器会将精度小的类型转换为精度大的类型以保持类型一致进行计算*/

/*运算符:
 * 1.算术运算符: + - * / %
 * 2.sizeof:计算表达式或类型的字节数
 * 3.()强制类型转换符
 * 4.关系运算符: == != < <= > >=
 * 5.逻辑运算符:&& || !
 * 6.位运算符:& | ^ ~ << >>
 * 7.自增运算符:++ --
 * 8.条件运算符:?:
 * 9.逗号运算符:, 表达式的结果是最后一个表达式的结果*/

// sizeof:计算表达式或类型的字节数
// 结果的类型是size_t(在32位平台是unsigned int 64位平台是unsigned long)
// ssize_t(32:signed int 64:signed long)
// sizeof运算符是在编译时进行计算的
void sizeofOpr() {
  printf("double size: %lu\n", sizeof(double));
  printf("int size: %lu\n", sizeof(int));
  unsigned int a = 3;
  // sizeof由于是在编译时计算,因为sizeof里面的表达式的类型在编译时即可确定
  // 而(a++) + (++a)是在编译链接好之后当程序加载到内存时才计算的
  printf("sizeof((a++) + (++a)): %lu\n", sizeof((a++) + (++a)));
  printf("a: %u\n", a);
}

/*算术运算符%:
 * 1.操作符两边的操作数必须是整型
 * 2.表达式结果的正负取决于操作符前面的操作数的符号*/
void arithmeticOpr() {
  int var = 10 % 3;
  printf("var is %d\n", var);

  // int var1 = 10.0 % 3;编译器首先将3隐式转换为double,但是%操作符不支持浮点数
}

// 关系运算符:结果只有真(非0)或者假(0)
void relationOpr() {
  int a = 10, b = 10;
  int c = (a == b);
  printf("c is %d\n", c);
  c = a != c;
  printf("c is %d\n", c);
}
// 逻辑运算符
void logicOpr() {
  bool var_false = false;
  bool var_true = true;
  // 短路求值
  int a_var = var_false && printf("var_false\n");
  int b_var = var_true || printf("var_true\n");

  printf("!var_true: %d\n", !var_true);
}
// 自增自减运算符++ --
void de_incrementOpr() {
  unsigned int a = 10;
  printf("a++ = %d\n", a++); // 10 a = 11
  printf("++a = %d\n", ++a); // 12 a = 12
  ++a;                       // a = 13
  printf("--a = %d\n", --a); // 12 a = 12
  printf("a-- = %d\n", a--); // 12 a = 11

  a = 20;
  // 无意义 因为不同的平台或者编译器或者编译器版本处理结果是不同的
  /*printf("%d %d %d\n",a++,++a,a++);*/
  // a++ = 20 a = 21
  // a = 24
  // ++a = 24 a = 22
  // a++ = 22 a= 23
  // a++ = 23 a = 24
  // ubuntu下是从后往前计算
  printf("%d %d %d %d %d\n", a++, a++, ++a, a, a++);
}
//逗号运算符:逗号表达式的结果是最后一个表达式的结果
//值得注意的是不可以在同一个表达式中对同一个变量又访问同时又进行修改.这是不合理的
//a = (b = 1) + (b + 1);
void commaOpr(){
  int a,b = 4;
  /*a = 3,b;//这个不是逗号表达式,a = 3是一个表达式,b本身也是一个表达式.逗号只是分开*/
  a = (3,b);
  printf("a: %d\n",a);

  /*a = (b = 1) + (b + 1);*/
  printf("a is %d\n",a);
}
//条件运算符: expr1 ? expr2 : expr3
//如果expr1的结果为真,则整个表达式的结果为expr2,否则就是expr3
void conditionOpr(){
  unsigned int condition_var = 3 > 4 ? 20:30;
  printf("condition_var: %u\n",condition_var);
}
int main() {
  /*sizeofOpr();*/
  /*arithmeticOpr();*/
  /*relationOpr();*/
  /*logicOpr();*/
  /*de_incrementOpr();*/
  /*commaOpr();*/
  conditionOpr();
  return 0;
}
