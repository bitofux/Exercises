/* 编写一个程序，实现以下功能:
 * 打开一个名为"example.txt"的文件，如果文件不存在则创建该文件
 * 向文件中写入字符串"Hello,World!\n"
 * 关闭文件
 * 重新打开该文件,以读取模式打开
 * 读取文件内容并打印到控制台
 * 再次关闭文件
 * */

#include <cstddef>
#include <cstdio>
#include <cstring>

int main() {
  FILE* fp;
  char buffer[] = "Hello,World!\n";
  size_t bytesWrite,bytesRead;
  //以只写权限打开一个名为example.txt的文件
  fp = fopen("exercise_15.txt","w");
  if (ferror(fp)) {
    perror("打开文件失败");
    return 1;
  }

  //写入数据到文件中
  bytesWrite = fwrite(buffer,sizeof(char),sizeof(buffer),fp);
  //检查是否写入错误
  if (ferror(fp)) {
    perror("写入文件时发生错误");
  }

  //关闭文件
  fclose(fp); 
  #if 1
  // 清空缓冲区
  memset(buffer, 0x0, sizeof(buffer));

  //重新打开该文件，以读取模式打开
  fp = fopen("exercise_15.txt", "r");
  if (ferror(fp)) {
    perror("打开文件失败");
  }
  
  //从文件读取数据到缓冲区
  bytesRead = fread(buffer, sizeof(char), sizeof(buffer), fp);
  //检查是否写入错误
  if (ferror(fp)) {
    perror("读取文件时发生错误");
  }
  //将缓冲区内容写入到控制台
  fprintf(stdout, "%s",buffer);
  //关闭文件
  fclose(fp);
  #endif
  return 0;

}
