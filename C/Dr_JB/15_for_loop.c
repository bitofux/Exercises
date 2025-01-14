/* 15_for_loop.c */
#include <stdio.h>
#include <assert.h>

#define F fflush(stdout)

void multi(unsigned int table,unsigned int var){
  printf("%u x %u = %u\n",table,var,table * var);
  return;
}
int main () {
  
  unsigned int table,var;
  printf("Select multiplication table: ");F;
  scanf("%u",&table);
  assert((table > 0) && (table < 13));

  for(var = 0;var < 13;var++)
    multi(table,var);

  return 0;
}
