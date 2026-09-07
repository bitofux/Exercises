/*
 * PROJECT : EXERCISES
 * FILE    : 13.externc.c
 * AUTHOR  : bitofux
 * DATE    : 2026-09-07
 * BRIEF   : extern "C" example
 */

#include <stdio.h>
extern int add(int a, int b);

int main(void) {
    printf("%d\n", add(10, 20));

    return 0;
}
