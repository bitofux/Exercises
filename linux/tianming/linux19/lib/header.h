/****************************************************
 * @file    header.h
 * @brief   一些有用的接口和宏、类型
 * @author  bitofux
 * @date    2025-10-05
 ****************************************************/
#pragma once
#include <time.h>
#include <netinet/in.h>
// typedef enum { ALIVE, DEAD } sta_t;
typedef struct {
    int fd;
    // sta_t status;
    struct timespec start;
    struct sockaddr_in client_addr;
} conn_t;

// 动态顺序表
typedef struct {
    conn_t* conn_data;
    int size;     // 实际元素个数
    int capcity;  // 顺序表的容量
} dym_seq_t;

// 初始化顺序表
int init(dym_seq_t* dym_seq, int capcity);

// 尾部插入
void push_back(dym_seq_t* dym_seq, conn_t conn);

// 通过fd获取对应连接对象在顺序表的下标
int get_index(dym_seq_t* dym_seq, int fd);

// 通用删除(依据下标删除)
void erase(dym_seq_t* dym_seq, int index);
// 扩容
void expand(dym_seq_t* dym_seq, int new_capcity);
// 打印
void show(dym_seq_t* dym_seq);
