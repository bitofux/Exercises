/****************************************************
 * @file    gets.c
 * @brief   gets函数
 * @author  bitofux
 * @date    2025-10-29
 ****************************************************/
#include <stdio.h>
int main() {
    char name[5] = {0};
    printf("输入您的姓名: ");
    gets(name);
    printf("name: %s\n", name);

    return 0;
}
