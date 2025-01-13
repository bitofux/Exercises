/* 08_random.c */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
unsigned int our_rand_function(unsigned int max) { return rand() % 10 + 1; }
int main() {
  srand(getpid());
  unsigned int max;
  unsigned int random = our_rand_function(max);
  printf("random: %u\n", random);
  return 0;
}
