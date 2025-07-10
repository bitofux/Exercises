//getchar and putchar
#include <cstdio>


int main() {
  char ch;
  printf("请输入一个字符: ");
  //获取一个字符
  ch = getchar();
  //输出一个字符
  putchar(ch);
  putchar('\n');

  return 0;
}
