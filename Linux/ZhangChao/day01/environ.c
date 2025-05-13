#include <stdio.h>

extern char **environ;

int main () {

  printf("environ = %p\n",environ);

  for(char **p = environ;*p;p++){
    printf("%s\n",*p);
  }

  return 0;
}
