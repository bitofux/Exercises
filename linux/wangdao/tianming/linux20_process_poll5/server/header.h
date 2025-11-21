/****************************************************
 * @file    header.h
 * @brief   头文件
 * @author  bitofux
 * @date    2025-11-01
 ****************************************************/
#pragma once
#include <stdint.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <sys/epoll.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <dirent.h>
#include <fcntl.h>

// 进程池中的进程数量
#define PROC_NUM 4
// 就绪数组的元素个数
#define READY_NUM 6
// 枚举类型
typedef enum { BUSY, NOT_BUSY } sta_t;
// 定义pro_t类型保存每个进程的属性
typedef struct {
    pid_t pid;
    sta_t status;
    int local_fd;
} proc_t;
// 初始化进程池
int init_process_poll(proc_t* list, int num);
// 接收父进程传来的数据
int recv_fd_from_parent(int fd, int* net_fd);
// 子进程进程数据处理
int work(int fd);

// 建立tcp连接，服务器建立监听
int init_tcp_connect(int* fd, const char* ip, const unsigned short port);
// 添加监听对象到epoll实例
int add_fd_to_ep(int ep_fd, int fd, uint32_t events);
// 发送文件对象给空闲的子进程
int send_fd_to_chi_proc(proc_t* list, int num, int fd);
