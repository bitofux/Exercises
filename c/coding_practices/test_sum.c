/*
 * PROJECT : EXERCISES
 * FILE    : test_sum.c
 * AUTHOR  : bitofux
 * DATE    : 2026-09-26
 * BRIEF   :
 */
int shared = 10;

int sum(int* a, int n) {
    int i, s = 0;
    for (i = 0; i < n; ++i) {
        s += a[i];
    }
    return s;
}
