/*
  流程控制:指的是控制程序执行的流程
  根据对语句执行顺序的影响，将流程控制分为下面几类:
  1) 选择语句: if ... else, switch ... case
    if(条件){            |   switch (整型表达式){这里的整型可以是整数类型、字符类型，不能是浮点数、字符串}
      语句1;             |    case 常量表达式 常量表达式不能是变量，不可出现函数调用,只能是11 -11 'a',或者一个整型常量的范围等等
      }                        语句;break;
                              default:
    if(条件){            |     语句;最后一个分支的break可以省略，但是如果也没有执行语句的话，必须加一个;号.
      语句1;             |
      }                  |
    else{                |
      语句2;             |
      }

    if(条件1){           |
      语句1;             |
      }                  |
    else if(条件2){      |
      语句2;             |
      }                  |
    else{                |
      语句2;             |
      }

    if(条件1){           |
      if(条件2){         |
        语句1;           |
      else {             |
        语句2;           |
        }                |
      }                  |
    }else {              |
      语句3;             |
    }                    |
  2) 循环语句: for, while, do ... while
  3) 跳转语句: return, break, continue, goto
  复合语句:将很多要执行的语句放在一对{}中，就形成了复合语句
  空语句: 什么也不做的语句
 */
#include <stdio.h>
#include <stddef.h>

void test_if() {
  size_t year = 0;
  printf("sizeof(size_t): %lu",sizeof(size_t));
  printf("请您输入一个年份: ");
  scanf("%lu", &year);
  if ((!(year % 4) && !(year % 100)) || (!(year % 400))) {
    printf("%lu是闰年!\n", year);
  } else {
    printf("%lu不是闰年\n", year);
  }

  //else的悬挂问题
#if 0
  int a = 1,b = 2;
  if(a != 0)
    if(b == 0 )
      printf("a != 0 b != 0 \n");
  else
    printf("a == 0\n");
  //当前写的代码else本来是匹配第一个if语句的，但由于C中的最近原则，else会与离自己最近且未与其他else匹配的if语句进行匹配，也就是说这个else会与第二个if进行匹配//因此b == 0是不成立的，随后执行else下的printf。最好的解决方法就是加上花括号
#endif
  int a = 1,b = 2;
  if(a != 0){
    if(b == 0){
      printf("a != 0 b != 0\n");
    }
  }else{
    printf("a == 0\n");
  }
}
void test_switch(){
 
  unsigned short age = 0;
  printf("输入您的年龄: ");
  scanf("%hu",&age);
  switch (age){// 比if ... else if ... else if ... else更加直观.但是请注意这不是C语言的标准，这只是GCC的扩展语法
    case 0 ... 10:{
      printf("童年\n");
      break;
    }
    case 11 ... 17:{
      int a = 100;//在case下是可以定义变量的，但是当前的case需要加上花括号，因为编译器界定一个变量的范围就是依赖的一对{}。如果不加上的话，这个声明语句是在当前case下管理的，那么编译器又会去寻找离他最近的花括号也就是switch对应的，不知道到底是在哪个范围了，因此编译器就会报错。所以无论是if还是switch最好都加上花括号。
      printf("青少年\n");
      printf("a = %d\n",a);
      break;
    }
    case 18 ... 34: {
      printf("成年\n");
      break;
    }
    case 35 ... 60:{
      printf("中年\n");
      break;
    }
    default:
      printf("老年\n");
  }

}
int main () {
  test_if();
  return 0;
}
