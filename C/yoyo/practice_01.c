#include <stdio.h>

/*1.写出能完成下面功能的语句: */
void one(){
  int a = 10,b = 20,x = 10,c = 0,n = 9,k = 2,m = 0,q = 2,p = 0,d = 2;
  //a.把变量x的值增加10
  x += 10;
  //b.把变量a和变量b之和的两倍赋值给c
  c = (a + b) * 2;
  //c.把变量a与两倍的b之和赋值给c
  c = a + b * 2;
  //d.把n除以k所得的余数赋值给m
  m = n % k;
  //e.用b减去a的差去除q,并将结果赋值给p
  p = (b - a) / q;
  //f.用a与b的和除以c与d的乘积,并将结果赋值给x
  x = (a + b) / (c * d);
}
/*2.下面每条语句执行以后,i和j的值分别是多少(假设i的初值是1,j的初值是2)*/
void two() {
  //a.i += j: i = 3 j = 2
  //b.i--: i = -,j = 2
  //c.i * j / i: i = 1,j = 2
  //d.i % ++j: i = 1,j = 3;
}
/*3.给出下面的程序片段的输出结果,假设i和j都是int类型的变量*/
void three(){
  /*
   * i = 5;
   * i = ++i * 3 - 2;
   * j = ++i * 3 - 2;
   * printf("%d %d",i,j)*/
  int i = 5,j;
  i = (++i) * 3 - 2;
  j = ++i * 3 - 2;
  printf("%d %d\n",i,j);
}

int main (){
  three();
}

