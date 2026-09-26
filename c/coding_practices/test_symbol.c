/*
 * PROJECT : EXERCISES
 * FILE    : test_symbol.c
 * AUTHOR  : bitofux
 * DATE    : 2026-09-26
 * BRIEF   :
 */
#include <stdio.h>

extern int shared;
int sum(int* a, int n);

int array[2] = {1, 2};
static int m = 10;

static void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main() {
    static int b = 4;
    int val = sum(array, 2);
    swap(&val, &shared);
    printf("%d, %d\n", val, shared);

    return val;
}
