#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

int main () {
  int* p = malloc(0xffffffffffffff);
  if(!p){
    fprintf(stderr,"errno:%d\n",errno);
    fprintf(stderr,"malloc:%s\n",strerror(errno));
  }
  FILE* fp = fopen("file.c","r");
  if(!fp){
    fprintf(stderr,"fopen:%s\n",strerror(errno));
    perror("fopen");
  }
  return 0;
}
