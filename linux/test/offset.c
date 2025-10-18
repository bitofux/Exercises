/****************************************************
 * @file    offset.c
 * @brief   编译期计算结构体成员的偏移量
 * @author  bitofux
 * @date    2025-10-09
 ****************************************************/
#include <stdio.h>
#include <stddef.h>
struct student {
    char name[64];
    int age;
};

// 嵌入结构体成员 也是要拆开来看
// 将嵌入过来的结构体的成员与当前结构体的成员
// 一起观察
struct stu {
    struct student s1;
    double price;
    float fl;
};

int main() {
    printf("sizeof student is %zu\n", sizeof(struct student));
    printf("age offset is %zu\n", offsetof(struct student, age));
    printf("sizeof stu is %zu\n", sizeof(struct stu));
    printf("price offset is %zu\n", offsetof(struct stu, price));
}
