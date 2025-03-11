.section .data
  msg:
    .ascii "Hello World\n"
.section .text
.globl _start
_start:
  movl $4,%eax # system call number for write

  movl $1,%ebx # file descripter
  movl $msg,%ecx # buffer pointer
  movl $0x0F,%edx # msg count
  
  int $0x80 

  movl $1,%eax #system call number for exit
  movl $0,%ebx #exit code 
  int $0x80
