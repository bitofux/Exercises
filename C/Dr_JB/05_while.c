/* 05_while.c */
#include <stdint.h>
#include <stdio.h>

int main () {

  uint8_t var = 0;

  while(var != 1){
    printf("Do you want to quiet? press 1\n");
    scanf("%hhu",&var);
  }

  return 0;
}
