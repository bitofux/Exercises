/*
 * PROJECT : EXERCISES
 * FILE    : 2.calloc_in_cpp.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-09-09
 * BRIEF   : calloc
 */
#include <cstdio>
#include <cstdlib>

int main() {
    int* ptr = static_cast<int*>(calloc(5, sizeof(int)));
    if(ptr == nullptr) {
        fprintf(stderr, "calloc: failed callocated memory");
        return EXIT_FAILURE;
    }

    for (int i = 0; i < 5; ++i) {
        printf("%d ", *(ptr + i));
    }

    free(ptr);
    ptr = nullptr;
    return EXIT_SUCCESS;
}
