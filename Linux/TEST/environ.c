#include <stdio.h>

extern char **environ;

int main (int argc,char **argv,char **env){
  
  printf("environ = %p\n",environ);
  printf("environ = %p\n",env);

  for(char **p = env;*p;p++)
      printf("%s\n",*p);

  return 0;
} 
