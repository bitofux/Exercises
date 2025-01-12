/* 04_float.c */
#include <stdio.h>


int main () {

  float pi = 3.14f;
  float r;
  printf("What is the r in cm? \n");
  scanf("%f",&r);
  double area = pi * r * r;
  printf("The area is %f\n",area);

  return 0;
}
