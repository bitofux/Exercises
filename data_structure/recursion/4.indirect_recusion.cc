/*
 * PROJECT : EXERCISES
 * FILE    : 4.indirect_recusion.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-08-05
 * BRIEF   :
 */
#include <cstdio>

void funcB(int n);

void funcA(int n) {
    if (n > 0) {
        printf("%d ", n);
        funcB(n - 1);
    }
}

void funcB(int n) {
    if (n > 1) {
        printf("%d ", n);
        funcA(n / 2);
    }
}

int main(void) {
    int x = 20;

    funcA(x);

    return 0;
}
