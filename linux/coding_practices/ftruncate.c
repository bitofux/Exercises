/****************************************************
 * @file    ftruncate.c
 * @brief   ftruncate
 * @author  bitofux
 * @date    2025-11-06
 ****************************************************/
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int main() {
    int fd = open("mytest.txt", O_CREAT | O_RDWR, 0644);
    if (fd < 0) {
        perror("open");
        return -1;
    }

    // 设置文件大小
    int ret = ftruncate(fd, 10 * 1024 * 1024);
    if (ret < 0) {
        perror("ftruncate");
        return -1;
    }
    // 清空文件
    // ret = truncate("mytest.txt", 0);
    ret = ftruncate(fd, 1024);

    int len = lseek(fd, 0, SEEK_END);
    if (len < 0) {
        perror("lseek");
        return -1;
    }
    printf("file size: %d\n", len);
}
