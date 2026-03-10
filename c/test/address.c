/*
 * PROJECT : EXERCISES
 * FILE    : address.c
 * AUTHOR  : bitofux
 * DATE    : 2026-03-07
 * BRIEF   : 测试16字节对齐
 */
#include <stdio.h>
#include <stdlib.h>

int main() {
    int* ptr = (int*)malloc(sizeof(int));
    *ptr = 10;

    unsigned long long int_ptr = (unsigned long)ptr;
    printf("ptr: %p\n", ptr);
    printf("int_ptr: %lld\n", int_ptr);

    if ((int_ptr & 15) == 0) {
        printf("is\n");
    }
    return 0;
}
