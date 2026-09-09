/*
 * PROJECT : EXERCISES
 * FILE    : 1.malloc_in_c.c
 * AUTHOR  : bitofux
 * DATE    : 2026-09-09
 * BRIEF   : malloc
 */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int* ptr = malloc(sizeof(int));
    if (ptr == NULL) {
        fprintf(stderr, "malloc: failed allocated memory");
        return EXIT_FAILURE;
    }
    *ptr = 5;
    printf("ptr: %d\n", *ptr);

    free(ptr);

    return EXIT_SUCCESS;
}
