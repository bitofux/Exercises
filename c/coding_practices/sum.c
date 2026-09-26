/*
 * PROJECT : EXERCISES
 * FILE    : sum.c
 * AUTHOR  : bitofux
 * DATE    : 2026-09-26
 * BRIEF   :
 */
int sum(int* a, int n) {
    int i, s = 0;
    for (i = 0; i < n; ++i) {
        s += a[i];
    }
    return s;
}
