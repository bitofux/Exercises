#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
void my_tree(const char* dirname) {
    if (dirname == NULL) {
        return;
    }
    DIR* dir = opendir(dirname);
    struct dirent* entity = readdir(dir);
    static int flag = 0;

    while (entity != NULL) {
        if (entity->d_type == DT_DIR && (strcmp(entity->d_name, ".") != 0) &&
            (strcmp(entity->d_name, "..") != 0)) {
            ++flag;
            char* ptr = (char*)malloc(sizeof(char) * (flag + 1));
            for (int i = 0; i < flag; ++i) {
                ptr[i] = ' ';
            }
            ptr[flag] = '\0';
            printf("%s|_", ptr);
            printf("%s\n", entity->d_name);
            char new_path[100] = {0};
            strcat(new_path, dirname);
            strcat(new_path, "/");
            strcat(new_path, entity->d_name);
            my_tree(new_path);
        } else if ((strcmp(entity->d_name, ".") != 0) && (strcmp(entity->d_name, "..") != 0)) {
            if (flag == 0) {
                printf("|_ ");
                printf("%s\n", entity->d_name);
            } else {
                // printf("|_");
                int new_flag = flag * 2;
                char* ptr = (char*)malloc(sizeof(char) * (new_flag + 1));
                for (int i = 0; i < new_flag; ++i) {
                    ptr[i] = ' ';
                }
                ptr[new_flag] = '\0';
                printf("%s|_", ptr);
                printf("%s\n", entity->d_name);
                free(ptr);
            }
        }
        entity = readdir(dir);
    }
    flag /= 2;
}
int main(int argc, char** argv) {
    if (argc < 2 || argc > 2) {
        fprintf(stderr, "usage: mytree file\n");
        return -1;
    }
    printf("%s\n", argv[1]);
    my_tree(argv[1]);

    return 0;
}
