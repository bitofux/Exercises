/*
 * PROJECT : EXERCISES
 * FILE    : test_offsetof.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-07-02
 * BRIEF   :  
 */
#include <stdint.h>
#include <iostream>

#define myoffsetof(type,mem) ((size_t)(&((type*)0)->mem))


struct node {
    int data;
    float a;
};
int main() {
    std::cout << "offset: " << myoffsetof(node,a) << std::endl;
}
