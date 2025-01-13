/* 06_if.c */

#include <stdio.h>

int main () {

  unsigned int speed = 0;

  printf("How fast are you driving?(km/h)\n");
  scanf("%u",&speed);

  if(speed > 100){
    printf("You are driving fast!\n");
  }else if(speed > 80){
    printf("You are driving perfectly fine\n");
  }else {
    printf("OK\n");
  }

  return 0;
}
