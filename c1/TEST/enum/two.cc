//使用位域来表示枚举
#include <cstdio>

enum FLAG {OFF = 0, ON = 1};

struct {
  enum FLAG flag1 : 1;
  enum FLAG flag2 : 1;
  enum FLAG flag3 : 1;
} flags;

int main() {
  flags.flag1 = ON;
  flags.flag2 = OFF;
  flags.flag3 = ON;

  printf("flag1: %d\n", flags.flag1);
  printf("flag1: %d\n", flags.flag2);
  printf("flag1: %d\n", flags.flag3);

  return 0;
}
