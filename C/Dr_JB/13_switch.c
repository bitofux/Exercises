/* 13_switch.c */
#include <stdint.h>
#include <stdio.h>

int main() {
  uint8_t var;

  printf("Choose between 1.apples 2.pears 3.bananas 4.something else: ");
  fflush(stdout);
  scanf("%hhu", &var);

  /*if(var == 1)*/
  /*  printf("apples\n");*/
  /*else if (var == 2)*/
  /*  printf("pears\n");*/
  /*else if(var == 3)*/
  /*  printf("bananas\n");*/
  /*else */
  /*  printf("something else\n");*/

  switch (var) {
  case 1:
    printf("apples\n");
    break;
  case 2:
    printf("pears\n");
    break;
  case 3:
    printf("bananas\n");
    break;
  default:
    printf("something else\n");
  }

  return 0;
}
