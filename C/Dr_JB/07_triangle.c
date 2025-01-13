/* 07_triangle.c */
#include <stdio.h>

unsigned int triangle(unsigned int base,unsigned int height){
  return (base * height) / 2;
}

int main () {

  unsigned int base,height,area;

  printf("base: ");
  fflush(stdout);
  scanf("%u",&base);

  printf("height: ");
  fflush(stdout);
  scanf("%u",&height);

  area = triangle(base,height);
  printf("area: %u\n",area);

  return 0;

}
