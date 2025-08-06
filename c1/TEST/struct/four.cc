#include <cstdio>
#include <cstring>

struct Student {
  char name[50];
  int age;
  int student_id;
};

//值传递
void printStudentByVal(struct Student stu) {
  printf("Name: %s, Age: %d, Student ID: %d\n", stu.name,stu.age, stu.student_id);
}

//指针传递
void printStudentByPtr(struct Student* stu) {
  printf("Name: %s, Age: %d, Student ID: %d\n", stu->name,stu->age,stu->student_id);
}

int main() {
  struct Student stu = {"Alice",20,1001};

  // 指针传递调用
  printStudentByPtr(&stu);

  //值传递调用
  printStudentByVal(stu);

  return 0;
}
