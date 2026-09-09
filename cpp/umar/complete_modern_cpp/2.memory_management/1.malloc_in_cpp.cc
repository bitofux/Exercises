/*
 * PROJECT : EXERCISES
 * FILE    : 1.malloc_in_cpp.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-09-09
 * BRIEF   : malloc
 */
#include <cstdio>
#include <cstdlib>

int main() {
    int* ptr = static_cast<int*>(malloc(sizeof(int)));
    if (ptr == nullptr) {
        fprintf(stderr, "malloc: faied allocated memory");
        return EXIT_FAILURE;
    }
    *ptr = 10;
    printf("*ptr: %d\n", *ptr);

    free(ptr);
    ptr = nullptr;
    free(ptr);

    return EXIT_SUCCESS;
}
