;;
;; PROJECT : EXERCISES
;; FILE    : one.asm
;; AUTHOR  : bitofux
;; DATE    : 2026-08-05
;; BRIEF   : 测试
;;

section .data

sum: DD 0

section .text
global _main

_main:
  mov eax,25
  mov ebx,50
  add eax,ebx
  mov DWORD [sum],eax

  mov eax,1
  mov ebx,0
  int 80h
