/* 09_sleep.c */

#include <stdio.h>
#include <unistd.h>

int main () {

  printf("wait while processing ... ");
  fflush(stdout);

  sleep(2);
  printf("ok\n");

  return 0;
}
