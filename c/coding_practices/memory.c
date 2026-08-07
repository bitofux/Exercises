/*
 * PROJECT : EXERCISES
 * FILE    : memory.c
 * AUTHOR  : bitofux
 * DATE    : 2026-08-07
 * BRIEF   :
 */
#include <stdio.h>

struct stu {
    int len;
    int a;
    int b;
    int s[4];
};

struct root {
    struct stu* p_stu;
};

int main() {
    struct root r = {.p_stu = 0};

    printf("%p",(*(r.p_stu)).s);

    return 0;
}
