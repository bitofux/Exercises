// 显示模块的实现
#include "show.h"
#include <stdio.h>

void show(const int left, const char op, const int right, const int res) {
  printf("%d %c %d = %d\n", left, op, right, res);
}
