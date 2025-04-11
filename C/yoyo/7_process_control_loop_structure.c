//循环结构:while do...while for
#include <stddef.h>
#include <stdio.h>

//while循环
/*
 * 语法:
 *  while (条件){
 *    //循环体
 *
 *    //控制条件的变量
 *  }
 */
void while_loop() {
  //计算用户输入整数的阶乘
  printf("请输入一个整数: ");
  int sum = 0;
  scanf("%d",&sum);
  int result = 1;
  while(sum >= 1){
    result *= sum;
    --sum;
  }
  printf("result = %d\n",result);
  }

/*
 * do{
 *  循环体
 * }while(条件)
 * 会先执行一次循环体，再去判断条件决定是否继续执行循环体。while是先判断条件再决定是否执行循环体。 
 */
void do_while_loop() {
  //计算一个整数的位数
  printf("请您输入一个整数: ");
  int sum = 0;
  scanf("%d",&sum);
  //定义一个变量用于位数计数
  int bit_sum = 0;
#if 0
  if (sum == 0) bit_sum = 1;
  else {
    while(sum){
    bit_sum++;
    sum = sum / 10;
  }
  }
  printf("bit_sum = %d\n",bit_sum);
#endif
//使用do .. while可以避免讨论整数为0的情况,即使条件不满足也可以执行一次
  do{
    bit_sum++;
    sum = sum / 10;
  }while(sum);
  printf("bit_sum = %d\n",bit_sum);
}

/*
 * for(初始化表达式;条件表达式;更新表达式){
 * 循环体;
 * }
 * 1.初始化表达式:在循环开始前执行一次,通常用来初始化循环计数器  可以是用逗号表达式连接的多条语句
 * 2.条件表达式:每次循环开始前检查，若为真，则执行循环体，否则退出循环 这个也可以是多条语句，但是注意如果使用逗号表达式，则整个条件表达式依赖逗号表达式的最后一个表达式结果，这个是需要注意的。一般来说多个条件可以使用&&或者||连接。
 * 3.更新表达式:每次循环后执行，通常用于更新循环计数器 这个也可以是多条语句
 *
 * 执行顺序:
 * 1.执行一次初始化表达式
 * 2.检查条件表达式是否为真，为真执行循环体，否则结束循环
 * 3.执行更新表达式
 * 4.返回步骤2
 *
 * 三个表达式都是可选，可省略初始化表达式，可省略条件表达式，可省略更新表达式
 * 全部省略就是for的死循环for(;;);
*/
//计算从1开始直到用户传递的数据的和
void for_loop() {
#if 0
  使用注意1：
    for(int i = 0;i < 10;i++,a--){ 这个写法是错误的， a的作用范围仅仅是{}内，不可以在其他地方使用，否则就是未声明。不要被误导。
    int a = 10;
  }
  使用注意2:
  for(int i = 0;i < 10;i++){这个写法是可以的， 我们要注意,()内的int i = 0的i的作用范围是()+{}，而int i = 10的作用范围仅仅是{}内，因此在{}内第一个i是对第二个i进行隐藏的
    int i = 10;
  }
#endif
  size_t num = 0,sum = 0;
  printf("请输入一个整数: ");
  scanf("%lu",&num);
  
  for(size_t i = 1;i <= num;i++) sum += i;

  printf("sum = %lu\n",sum);
}
int main () {
  /*while_loop();*/
  /*do_while_loop();*/
  for_loop();
  return 0;
}
