/*
 * PROJECT : EXERCISES
 * FILE    : 3.realloc_in_cpp.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-09-09
 * BRIEF   : realloc
 */
#include <cstdio>
#include <cstdlib>

int main() {
    int* ptr = static_cast<int*>(malloc(sizeof(int) * 5));
    if(ptr == nullptr) {
        fprintf(stderr, "malloc: failed callocated memory");
        return EXIT_FAILURE;
    }
    for (int i = 0; i < 5; ++i) {
        *(ptr + i) = i + 1;
    }

    int* ptr_ = static_cast<int*>(realloc(ptr, sizeof(int) * 10));
    if(ptr_ == nullptr) {
        fprintf(stderr, "realloc: failed callocated memory");
        return EXIT_FAILURE;
    }
    for (int i = 0; i < 10; ++i) {
        printf("%d ", *(ptr_ + i));
    }

    free(ptr_);

    return 0;
}
