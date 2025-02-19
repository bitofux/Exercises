/*gcc:之前的全名是GNU C Compiler.但现在它不是一个单独的C编译器，它的全称是GNU COMPILER COLLECTION，是GNU编译器集合*/
//使用gcc在linux发行版上编译源文件时，分为四个步骤，也涉及了多个可执行程序

/*
 * 1.预处理(cpp): 使用cpp可执行程序完成，主要处理源文件中的预处理指令和对宏的展开并删除注释 
   gcc -E 02_c_compiler_process.c -o 02_c_compiler_process.i 
   cpp 02_c_compiler_process.c -o 02_c_compiler_process.i
 * 2.编译(cc1): 使用cc可执行程序完成，将预处理之后的翻译单元做语法、语义、词义的分析并做一些适当的代码优化
   gcc -S 02_c_compiler_process.i -o 02_c_compiler_process.s
   cc1 02_c_compiler_process.i -o 02_c_compiler_process.s
 * 3.汇编(as): 使用as可执行程序完成，将汇编指令翻译成当前cpu架构支持的机器指令
   gcc -c 02_c_compiler_process.s -o 02_c_compiler_process.o
   as 02_c_compiler_process.s -o 02_c_compiler_process.o
 * 4.链接(ld): 使用ld可执行程序完成，将汇编阶段生成的目标文件中的符号与需要的库文件中的符号进行动态链接
   gcc 02_c_compiler_process.o -o 02_c_compiler_process
 * */
//g++: cpp中的编译器前端是cc1plus
#include <stdio.h>

int main () {

  printf("hello bitofux\n");
  return 0;

}



