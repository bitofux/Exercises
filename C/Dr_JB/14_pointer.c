/* 14_pointer.c */

#include <stdio.h>
#include <string.h>

int main () {

  char str[32];
  strncpy(str, "I LIKE PEARS!", 31);
  printf("str: %s\n",str);

  char* ptr = str;
  printf("ptr: %s\n",ptr);
  ptr++;
  printf("ptr: %s\n",ptr);

  return 0;
}
