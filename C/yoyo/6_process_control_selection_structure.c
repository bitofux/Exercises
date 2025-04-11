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
      int a = 100;//在case下是可以定义变量的，但是当前的case需要加上花括号，因为编译器界定一个变量的范围就只看它所在的一对{}。那么显然在当前case分支没加{}之前，编译器认为a变量的作用范围在switch的一对{}中，但是发现a定义的位置是在当前case中，所以编译器不明确a的作用范围究竟是哪个了，所以干脆直接报错。
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
  //还有一个在switch中值得注意的点
  const int a = 20;
  switch(a){
    int b= 20;//在这里定义一个变量并初始化的语句，不会在switch中执行，因为switch的执行逻辑就是直接匹配case,但是由于这个b是在switch中的一对{}中，编译器会认定这个变量是在这个作用范围内，会为其分配内存空间，但是具体是什么值看编译器的版本或者种类。
    case 10:
      printf("b = %d\n",b);
      break;
    case 20:
      printf("b = %d\n",b);
      break;  
  }

}
//if使用注意
void if_use_note() {
#if 0
  //1.与case不加{}定义变量一样的问题
  int a = 0;
  if(a == 0){
    int b = 10;//使用if不加{}时，if只管理其对应的一条语句，那么int b = 10;是被if所管理，但是编译器界定一个变量的作用范围是最近的{}也就是这个if_use_note函数的{},但是这个变量同时又被if所管理，因此编译器就不明确了，就会报错。解决报错的原因就是加上花括号，让其作用范围明确。
  }
  /*printf("b = %d\n",b);//报错的原因是b的作用范围是属于上面的if语句的，当花括号结束，b也就被自动的回收了，因此这里的b是一个未声明的变量，在C中，未声明的变量不可使用*/
#endif
//2.变量名隐藏
#if 1
  int a = 10;
  if(a == 10){
    printf("a = %d\n",a);//输出的是第一个a，因为此时在if作用域内可见的a只有一个
    int a = 30;
    printf("a = %d\n",a);//输出的是在if内定义的a，因为此时在if作用域内有a的定义，就会将第一个a给隐藏
  }
#endif
}

//if...else和switch是否可以互相等价转换？答案是否定的
//可以使用switch形式，一定可以转换为if...else反之是不成立的
void if_to_switch() {

  int age = 65;
  if(age > 60){
    printf("老年\n");
  }
  //这个形式就无法转换为switch
}




int main () {
  /*test_if();*/
  /*test_switch();*/
  if_use_note();
  return 0;
}
