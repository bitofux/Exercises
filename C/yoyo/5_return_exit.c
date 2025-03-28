#include <stdio.h>


void foo() {
  //系统预定义的宏,用于帮助调试程序
  printf("file name: %s\n",__FILE__);
  printf("function name: %s\n",__func__);
  printf("function name: %s\n",__FUNCTION__);
  printf("line number: %d\n",__LINE__);
  printf("date: %s\n",__DATE__);
  printf("time: %s\n",__TIME__);

  printf("IS STDC: %d\n",__STDC__);
}
int main () {

  foo();

}
