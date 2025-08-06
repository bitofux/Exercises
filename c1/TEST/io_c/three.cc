#include <cstddef>
#include <cstdio>
#include <cstring>
#include <iostream>

#define BUFFER_SIZE 10 //每次读取的字节数

int main() {
  FILE* fp;
  char buffer[BUFFER_SIZE];
  size_t bytesRead;

  //打开文件用于读取
  fp = fopen("example.txt", "r+");
  if (fp == NULL) {
    perror("打开文件失败");
    return 1;
  }

  //分段读取文件内容
  while ((bytesRead = fread(buffer, sizeof(char), BUFFER_SIZE, fp)) > 0) {
    //输出读取到的数据
    fwrite(buffer, sizeof(char), bytesRead, stdout);
  }

  //输出当前文件指针位置
  std::cout << ftell(fp) << std::endl;

  //将文件指针位置重置为文件开头
  fseek(fp, 0, SEEK_SET);

  //往文件写入数据覆盖之前
  const char* ptr = "bitofux come on!!";

  fwrite(ptr, sizeof(char), strlen(ptr), fp);
  if (ferror(fp)) {
    perror("写入文件时发生错误");
  }

  //检查是否发生读取错误
  if (ferror(fp)) {
    perror("读取文件时发生错误");
  }

  //关闭文件
  fclose(fp);

  return 0;

}
