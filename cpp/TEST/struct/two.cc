#include <cstring>
#include <cstdio>
//定义一个名为Student的结构体，包括姓名、年龄和学号三个成员
struct Student {
  char name[50];
  int age;
  int student_id;
};

//使用结构体标签声明结构体变量
struct Student stu1, stu2;

//或者在定义结构体的同时声明变量
struct {
  char name[50];
  int age;
  int student_id;
} stu3; //stu3是一个匿名结构体的变量

int main() {
  //在定义时初始化结构体变量
  struct Student stu = {"Alice",20,2001};

  //或者使用字符串复制函数初始化字符数组类型的成员
  struct Student stu2;
  strcpy(stu2.name, "Bob");
  stu2.age = 22;
  stu2.student_id = 1002;
  
  printf("Name: %s, Age: %d, Student ID: %d\n",stu.name,stu.age,stu.student_id);
  printf("Name: %s, Age: %d, Student ID: %d\n",stu2.name,stu2.age,stu2.student_id);

  return 0;
}
