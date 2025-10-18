/****************************************************
 * @file    header.c
 * @brief   实现
 * @author  bitofux
 * @date    2025-10-05
 ****************************************************/
#include "header.h"
#include <stdio.h>
#include <stdlib.h>

int init(dym_seq_t* dym_seq, int capcity) {
    if (dym_seq == NULL || capcity <= 0) {
        fprintf(stderr, "null pointer or capcity is zero\n");
        return -1;
    }
    conn_t* tmp = (conn_t*)malloc(sizeof(conn_t) * capcity);
    if (NULL == tmp) {
        fprintf(stderr, "malloc is failed\n");
        return -1;
    }
    dym_seq->conn_data = tmp;
    dym_seq->capcity = capcity;
    dym_seq->size = 0;
    return 0;
}
void show(dym_seq_t* dym_seq) {
    for(int i = 0; i < dym_seq->size;++i) {
        printf("fd: %d\n",dym_seq->conn_data[i].fd);
    }
}

void expand(dym_seq_t* dym_seq, int new_capcity) {
    if (dym_seq == NULL) {
        fprintf(stderr, "expand failed\n");
        return;
    }
    // 使用新的容量开辟一块新的内存
    conn_t* tmp = (conn_t*)malloc(sizeof(conn_t) * new_capcity);
    if (tmp == NULL) {
        fprintf(stderr, "malloc is failed\n");
        return;
    }
    // 拷贝数据
    for (int i = 0; i < dym_seq->size; ++i) {
        tmp[i] = dym_seq->conn_data[i];
    }
    // 更新其他数据
    dym_seq->capcity = new_capcity;
    // 释放原来的内存
    free(dym_seq->conn_data);
    dym_seq->conn_data = tmp;
}
void push_back(dym_seq_t* dym_seq, conn_t conn) {
    if (dym_seq == NULL) {
        fprintf(stderr, "dym_seq is null\n");
        return;
    }
    if (dym_seq->size == dym_seq->capcity) {
        // 扩容
        expand(dym_seq, dym_seq->capcity * 2);
    }

    dym_seq->conn_data[dym_seq->size] = conn;
    dym_seq->size += 1;
}

void erase(dym_seq_t* dym_seq, int index) {
    if (dym_seq == NULL) {
        fprintf(stderr, "null address\n");
        return;
    }
    if (index < 0 || index >= dym_seq->size) {
        fprintf(stderr, "index invalid\n");
        return;
    }
    // 移动数据[index + 1,size - 1]
    for (int i = index + 1; i < dym_seq->size; ++i) {
        dym_seq->conn_data[i - 1] = dym_seq->conn_data[i];
    }

    dym_seq->size -= 1;
}
int get_index(dym_seq_t* dym_seq, int fd) {
    if (dym_seq == NULL) {
        fprintf(stderr, "invalid address\n");
        return -1;
    }
    for (int i = 0; i < dym_seq->size; ++i) {
        if (dym_seq->conn_data[i].fd == fd) {
            return i;
        }
    }
    return -1;
}
