#include <stdio.h>
#include <errno.h>
#include <error.h>

int main(int argc, char* const* argv) {
    // 发生错误之前输出errno的值
    printf("errno: %d\n", errno);
    FILE* fp = fopen("not_exist.txt", "r");
    printf("errno: %d\n", errno);

    // 使用perror函数输出错误信息
    //  perror("fopen");

    // 使用strerror函数
    //  fprintf(stderr, "%s: %s\n","fopen",strerror(errno));

    // 使用linux平台专有的error函数
    error(0, errno, "fopen");

    return 0;
}
