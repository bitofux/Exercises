/*编写一个程序，完成以下任务:
* 定义一个结构体Student,包含姓名(字符数组)和年龄(整型)
* 创建一个包含多个Student结构体的数组,并初始化
* 将这些结构体数据写入到"student.dat"的二进制文件中
* 从该文件中读取结构体数据，并打印到控制台.
*/
#include <cstdio>
#include <random>


struct Student {
  char student_name[20];
  int student_age;
};

int main() {
  Student stu[5];

  //输入五个同学的姓名和年龄
  for (int i = 0;i < 5;i++) {
    printf("第%d个同学的姓名和年龄(空格隔开): ",i+1);
    scanf(" %19s %d",stu[i].student_name,&stu[i].student_age);
    printf("\n");
  }

  //以读写权限打开一个名为students.dat的二进制文件
  FILE* fp = fopen("students.dat", "w+");
  if (!fp) {
    perror("打开文件失败");
    return 1;
  }

  //写入数据到二进制文件
  if ((fwrite(stu, sizeof *stu, 5, fp)) != 5) {
    perror("写入文件时错误");
    fclose(fp);
    return 1;
  }

  //文件指针设置为文件开头
  fseek(fp, 0, SEEK_SET);
  //循环从文件中读取数据到控制台
  Student s;
  while ((fread(&s, sizeof(s), 1, fp)) == 1) {
    //写入数据到控制台
    fprintf(stdout, "姓名: %s, 姓名: %d\n",s.student_name,s.student_age);
  }
  if (ferror(fp)) {
    perror("写入控制台错误");
  }
  fclose(fp);

  return 0;

}
