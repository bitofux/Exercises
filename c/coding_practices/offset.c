/*
 * PROJECT : EXERCISES
 * FILE    : offset.c
 * AUTHOR  : bitofux
 * DATE    : 2026-07-19
 * BRIEF   : 获取结构体特定数据成员的偏移量
 */
#include <stdio.h>

#define GET_OFFSET_OF(filed, type) (long)&(((struct type*)(0))->filed)

#pragma pack(push, 1)
struct student {
    int data;
    long age;
    char name[32];
};
#pragma pack(pop)

int main() { printf("offset of data in student: %ld", GET_OFFSET_OF(name, student)); }
