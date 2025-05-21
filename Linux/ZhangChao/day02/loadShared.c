#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  // 加载动态库
  void *handle = dlopen("./shared/libmath.so", RTLD_NOW);
  if (!handle) {
    fprintf(stderr, "dlopen:%s\n", dlerror());
    exit(EXIT_FAILURE);
  }
  // 获取函数地址
  int (*ptr_add)(int, int) = (int (*)(int, int))dlsym(handle, "add");
  if(!ptr_add){
    fprintf(stderr,"dlsym:%s\n",dlerror());
    exit(EXIT_FAILURE);
  }
  void (*ptr_show)(int, char, int, int) =
      (void (*)(int, char, int, int))dlsym(handle, "show");
  if(!ptr_show){
    fprintf(stderr,"dlstm:%s\n",dlerror());
    exit(EXIT_FAILURE);
  }
  // 使用函数
  ptr_show(20, '+', 10, ptr_add(20, 10));
  // 释放动态库
  if(dlclose(handle)){
    fprintf(stderr,"dlclose:%s\n",dlerror());
    return -1;
  }
  return 0;
}
