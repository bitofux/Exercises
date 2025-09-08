#include <stdio.h>
#include <error.h>
#include <errno.h>
#include <unistd.h>

#define MAX_SIZE 10
int main() {
    //如果使用用户态的缓冲区保存获取的当前工作目录
    //如果MAX_SIZE小于当前工作目录的字符长度
    //那么会出现报错:./a.out: getcwd: Numerical result out of range
    char buf[MAX_SIZE];
    const char* cwd = getcwd(buf, MAX_SIZE);
    printf("errno: %d\n",errno);
    error(0, errno, "getcwd");

    //因此我们根据man手册的描述信息,不使用用户态的缓冲区,直接
    //让内核根据我们当前的工作目录的字符长度创建相应的堆内存保存
    //但是记得free
    const char* get_cwd = getcwd(NULL, 0);
    printf("cwd: %s\n",get_cwd);

    return 0;
}
