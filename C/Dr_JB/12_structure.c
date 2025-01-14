/* 12_structure.c */
#include <stdint.h>
#include <stdio.h>
#include <string.h>

struct person {
  char title[12];
  char lastname[32];
  uint8_t age;
};

int main() {
  struct person p1;
  strncpy(p1.title, "programmer", 11);
  strncpy(p1.lastname, "bitofux", 8);
  p1.age = 26;
  printf("%s %s of age : %hhu\n", p1.title, p1.lastname, p1.age);

  return 0;
}
