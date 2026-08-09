/*
 * PROJECT : EXERCISES
 * FILE    : uintptr_t.c
 * AUTHOR  : bitofux
 * DATE    : 2026-08-10
 * BRIEF   : uintptr_t类型
 */
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

int main(void) {
    int x = 20;

    uintptr_t arr[] = {2, 3, 4, 5};

    uintptr_t* ptr_x = arr;

    size_t len = sizeof(arr) / sizeof(arr[0]);

    for (size_t i = 0; i < len; ++i) {
        printf("%lu ", ptr_x[i]);
    }

    return 0;
}
