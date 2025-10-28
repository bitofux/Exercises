/****************************************************
 * @file    header.h
 * @brief   进程池所需的类型、函数
 * @author  bitofux
 * @date    2025-10-28
 ****************************************************/
#pragma once
#include <stdint.h>
#include <unistd.h>

// 进程的忙闲状态
typedef enum {
    BUSY,    // 忙状态
    IDLESSE  // 闲状态
} status_t;
// 单个进程所拥有的属性
typedef struct {
    pid_t pid;        // 进程id
    status_t status;  // 进程状态
    int fd;           // 与父进程通信的fd
} child_proc_t;

// 初始化进程池
// 返回值: -1创建失败 0创建成功
int init_process_poll(child_proc_t* list, int num, int* sp);

// 初始化tcp连接
// 返回值: -1初始化失败 >0返回监听文件对象的文件描述符
int init_tcp_connect(const char* ip, const uint16_t port);

// 接收父进程传来的文件对象
int recv_fd_from_parent(int fd);

// 做任务
int do_work(int fd);

// 添加监听对象到epoll实例
void add_event(int ep, int fd, uint32_t events);

// 发送文件对象到子进程
void send_fd_to_son(child_proc_t* list, int nums, int fd, int* sp);
