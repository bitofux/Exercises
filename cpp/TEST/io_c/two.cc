//gets() and puts()
#include <cstdio>
#include <cstring>

int main() {
  char str[5];
  //gets很容易造成缓冲区溢出
  // const char* ptr = gets(str);

  //fgets这个函数是否读取换行符取决于你输入的字符个数是否小于n - 1,如果是则读取换行,如果是大于等于n - 1,则只会读取n - 1个字符
  const char* ptr = fgets(str,sizeof str,stdin);
  if (ptr == NULL) {
    if (feof(stdin)) {
      puts("遇到EOF,推出!");
    } else {
      perror("中断或出错!");
    }
  }
  fputs(ptr, stdout);

  // fputs(str, stdout);
  // puts(ptr);

  return 0;
}
