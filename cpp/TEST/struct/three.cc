#include <cstdio>

using student = struct Student {
    char name[50];
    int age;
    int student_id;
};

int main() {
    student stu = {"Alice", 20, 1001};

    // 访问结构体并打印
    printf("Name: %s\n", stu.name);
    printf("Age: %d\n", stu.age);
    printf("Student ID: %d\n", stu.student_id);

    return 0;
}
