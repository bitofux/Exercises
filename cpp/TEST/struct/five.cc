#include <cstdio>
#include <cstring>
#include <cstdlib>

//定义一个名为Person的结构体
struct Person {
  char name[50];
  int age;
};

//定义一个名为Employee的结构体，包含Person结构体作为成员
struct Employee {
  struct Person personal_info;
  char job_title[50];
};

//定义一个名为Node的结构体，包含指向自己类型的指针
struct Node {
  int data;
  struct Node* next;
};

int main() {
  // 初始化Employee结构体变量
  struct Employee emp;
  strcpy(emp.personal_info.name, "Alice");
  emp.personal_info.age = 30;
  strcpy(emp.job_title, "Engineer");

  //打印Employee结构体变量的信息
  printf("Name: %s, Age: %d, Job_Title: %s\n", emp.personal_info.name,emp.personal_info.age,emp.job_title);

  //创建链表节点
  struct Node* head = (struct Node*)malloc(sizeof *head);
  head->data = 1;
  head->next = NULL;

  struct Node* second = (struct Node*)malloc(sizeof *second);
  second->data = 2;
  second->next = NULL;
  
  head->next = second; // 将第二个节点链接到第一个节点之后

  //打印链表节点的数据
  struct Node* current = head;
  while (current) {
    printf("Data: %d\n", current->data);
    current = current->next;
  }

  //释放链表节点的内存
  free(head);
  free(second);

  return 0;
}
