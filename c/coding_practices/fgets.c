/****************************************************
 * @file    fgets.c
 * @brief   fgets函数
 * @author  bitofux
 * @date    2025-10-29
 ****************************************************/
#include <stdio.h>

int main() {
    char name[10];
    printf("enter your name: ");
    fgets(name, sizeof(name), stdin);

    printf("name: %s", name);
    return 0;
}
