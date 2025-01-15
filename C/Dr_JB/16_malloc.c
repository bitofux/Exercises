/* 16_malloc.c */
#include <stdio.h>
#include <stdlib.h>

#define NAME_LENGTH 32
int main () {

  char* name = (char*)malloc(NAME_LENGTH);
  printf("What is your name? ");
  fflush(stdout);
  scanf("%s",name);

  printf("Hello %s\n",name);

  return 0;
}
