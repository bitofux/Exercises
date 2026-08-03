/****************************************************
 * @file    dirent.c
 * @brief   测试读取目录
 * @author  bitofux
 * @date    2025-11-03
 ****************************************************/
#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

int main() {
    DIR* dir = opendir("./");
    struct dirent* entry = readdir(dir);
    char path[1024] = {0};
    struct stat st;

    while (entry != NULL) {
        snprintf(path, sizeof(path), "%s%s", "./", entry->d_name);
        int ret = stat(path, &st);
        if (ret < 0) {
            perror("stat");
            exit(1);
        }
        if (S_ISDIR(st.st_mode)) {
            entry = readdir(dir);
            continue;
        } else if (S_ISREG(st.st_mode)) {
            printf("name: %s\n", path);
        }
        entry = readdir(dir);
    }
}
