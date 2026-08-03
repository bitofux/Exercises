/****************************************************
 * @file    mmap.c
 * @brief   memory mmap
 * @author  bitofux
 * @date    2025-11-06
 ****************************************************/
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/mman.h>

int main() {
    int fd = open("./mytest.txt", O_RDWR);
    if (fd < 0) {
        perror("open");
        return -1;
    }
    // 利用lseek求打开文件大小
    off_t size = lseek(fd, 0, SEEK_END);
    if (size < 0) {
        perror("lseek");
        return -1;
    }
    // 创建映射区
    void* ptr = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (ptr == MAP_FAILED) {
        perror("mmap");
        return -1;
    }
    // 利用指针往内存映射区写入数据
    for (int i = 0; i < size; ++i) {
        *((char*)ptr + i) = 'a';
    }
    munmap(ptr, size);
    close(fd);
}
