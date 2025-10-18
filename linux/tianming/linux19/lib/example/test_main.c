/****************************************************
 * @file    test_main.c
 * @brief   测试
 * @author  bitofux
 * @date    2025-10-05
 ****************************************************/
#include <stdio.h>
#include <time.h>
#include "../header.h"

int main() {
    dym_seq_t dym_seq;
    init(&dym_seq, 10);

    for (int i = 0; i < 10; ++i) {
        conn_t conn;
        conn.fd = i + 1;
        clock_gettime(CLOCK_MONOTONIC, &conn.start);
        push_back(&dym_seq, conn);
    }
    show(&dym_seq);
    printf("size: %d,capcity: %d\n", dym_seq.size, dym_seq.capcity);

    conn_t conn;
    conn.fd = 11;
    push_back(&dym_seq, conn);

    printf("size: %d,capcity: %d\n", dym_seq.size, dym_seq.capcity);
    conn.fd = 12;
    push_back(&dym_seq, conn);
    show(&dym_seq);
    printf("size: %d,capcity: %d\n", dym_seq.size, dym_seq.capcity);

    erase(&dym_seq, get_index(&dym_seq, 5));

    show(&dym_seq);
    printf("size: %d,capcity: %d\n", dym_seq.size, dym_seq.capcity);
    return 0;
}
