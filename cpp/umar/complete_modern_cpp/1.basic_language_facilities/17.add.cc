/*
 * PROJECT : EXERCISES
 * FILE    : 17.add.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-09-08
 * BRIEF   : 测试匿名空间 
 */
namespace {
    int add(int a,int b) {
        return a + b;
    }
}

void print() {
    add(10, 20);
}
