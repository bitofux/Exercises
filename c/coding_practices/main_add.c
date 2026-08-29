/*
 * PROJECT : EXERCISES
 * FILE    : main_add.c
 * AUTHOR  : bitofux
 * DATE    : 2026-08-29
 * BRIEF   : main->add 
 */

int add(int a,int b) {
  int c = a+ b;
  return c;
}

int main(void) {
  int a = 3;
  int b = 2;
  int c = add(a, b);

  return 0;
}
