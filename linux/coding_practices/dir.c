#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>

void list_dirent(const char* dirname) {
    DIR* dir = opendir(dirname);
    if (dir == NULL) {
        perror("opendir");
        return;
    }

    struct dirent* entity = readdir(dir);

    while (entity != NULL) {
        printf("reading from %s\n", dirname);
        // 如果遇到.或者..会导致一直循环进入./. ../.
        if (entity->d_type == DT_DIR && (strcmp(entity->d_name, ".") != 0) &&
            (strcmp(entity->d_name, "..") != 0)) {
            char path[100] = {0};
            strcat(path, dirname);
            strcat(path, "/");
            strcat(path, entity->d_name);
            list_dirent(path);
        }
        printf("%s\n", entity->d_name);
        entity = readdir(dir);
    }
}
int main() {
    list_dirent(".");
    return 0;
}
