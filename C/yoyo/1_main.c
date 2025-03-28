//注释的多种方式

//:单行注释
/*:多行注释，不可以嵌套使用*/
#include <stdio.h>
#include <stdlib.h>
#if 0 //单独一行
预处理指令的方式进行注释
#endif //单独一行

int main () {
  /*
   * 转义字符\:将普通字符转为具有特殊含义的字符
   * \\ \/ \"等:将具有特殊含义的字符变成本身具有的含义*/
  printf("Hello World\n");//这里的\n表示的是换行

  /*EXIT_SUCCESS和EXIT_FAILURE是定义在stdlib.h头文件中的宏*/
  return EXIT_SUCCESS;
}
