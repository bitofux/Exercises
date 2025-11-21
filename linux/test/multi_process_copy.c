/****************************************************
 * @file    multi_process_copy.c
 * @brief   多进程拷贝
 * @author  bitofux
 * @date    2025-11-07
 ****************************************************/
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <stdlib.h>
#include <sys/wait.h>
int main() {
    int fd = open("copy.txt", O_RDWR | O_CREAT, 0644);
    if (fd < 0) {
        perror("open");
        exit(1);
    }
    int fd_one = open("copy_one.txt", O_CREAT | O_RDWR, 0644);
    if (fd_one < 0) {
        perror("open");
        return -1;
    }
    // 计算打开文件的大小
    off_t file_size = lseek(fd, 0, SEEK_END);
    if (file_size < 0) {
        perror("lseek");
        return 0;
    }
    // 计算每个进程需要拷贝的大小
    uint32_t process_size = file_size / 4;
    printf("process_size: %u\n", process_size);
    // 4个进程同时进行拷贝,计算每个进程拷贝的大小
    // 但是大小不一定会被4整除,可以计算这个文件对4取余数
    uint32_t mod = file_size % 4;
    printf("file_size: %ld\nmod is %u\n", file_size, mod);
    // 保存最后一个进程拷贝的大小
    uint32_t last_size = process_size + mod;

    // 为copy.txt建立映射区
    void* ptr = mmap(NULL, file_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (ptr == MAP_FAILED) {
        perror("mmap");
        return -1;
    }
    // 为目标文件建立映射区,大小与目标文件相同
    ftruncate(fd_one, file_size);
    void* ptr1 = mmap(NULL, file_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd_one, 0);
    if (ptr1 == MAP_FAILED) {
        perror("mmap");
        return -1;
    }

    pid_t pids[4] = {0};
    // 创建多个进程进行拷贝
    for (int i = 0; i < 4; ++i) {
        pid_t pid = fork();
        if (pid == 0) {
            if (i < 3) {
                strncpy(ptr1 + (i * process_size), ptr + i * process_size, process_size);
                exit(i);
            } else {
                strncpy(ptr1 + 3 * process_size, ptr + 3 * process_size, last_size);
                exit(i);
            }
        } else if (pid < 0) {
            perror("fork");
            return -1;
        } else {
            pids[i] = pid;
        }
    }
    // 等待所有子进程退出
    for (int i = 0; i < 4; ++i) {
        int status = 0;
        pid_t pid = waitpid(pids[i], &status, 0);
        if (pid > 0) {
            if (WIFEXITED(status)) {
                printf("child_process's pid: %d,status: %d\n", pid, WEXITSTATUS(status));
            }
        }
    }
}
