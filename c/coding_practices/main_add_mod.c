/*
 * PROJECT : EXERCISES
 * FILE    : main_add_mod.c
 * AUTHOR  : bitofux
 * DATE    : 2026-08-26
 * BRIEF   : main -> add -> mod
 */

int mod(int a, int b) { return a % b; }

int add(int a, int b) {
    int res = mod(a, b);
    return res + b;
}
int main(void) {
    int a = 3;
    int b = 2;
    int c = add(a, b);

    return 0;
}
