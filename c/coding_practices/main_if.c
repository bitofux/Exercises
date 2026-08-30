/*
 * PROJECT : EXERCISES
 * FILE    : main_if.c
 * AUTHOR  : bitofux
 * DATE    : 2026-08-30
 * BRIEF   : 简单的if语句
 */

int main(void) {
    int a = 3;
    int b = 2;
    int c;

    if (a <= b) {
        c = a + b;
    } else {
        c = a - b;
    }

    return c;
}
