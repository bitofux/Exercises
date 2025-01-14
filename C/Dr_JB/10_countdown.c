/* 10.countdown.c */
#include <stdio.h>
#include <unistd.h>

int main () {
  
  unsigned int number = 10;
  while(1){

    printf("%02u\r",number);
    fflush(stdout);
    sleep(1);
    --number;
    if(number < 1)
      break;
  }

  return 0;
}
