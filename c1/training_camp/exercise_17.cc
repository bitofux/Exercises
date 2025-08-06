/*
 * 编写一个程序，实现以下功能：
尝试打开一个名为"log.txt"的文件，以追加模式（"a"）打开。
向文件中追加当前日期和时间（可以使用标准库函数获取）。
如果文件打开失败，打印错误信息。
关闭文件。*/
#include <cstdio>
#include <cstring>
#include <ctime>

int main() {
    FILE *fp = fopen("log.txt", "a");

    // 获取当前时间
    time_t now = time(nullptr);
    if (now == ((time_t)(-1))) {
        perror("time error");
        return 1;
    }

    // 转换时间
    tm tm_info;
    localtime_r(&now, &tm_info);

    char buf[64];
    auto len = strftime(buf, sizeof buf, "%Y-%m-%d %H:%M:%S", &tm_info);

    // 将buf中的数据追加到log.txt中
    if (fwrite(buf, sizeof(char), strlen(buf), fp) != len) {
        perror("写入文件错误");
        fclose(fp);
        return 1;
    }

    // 关闭文件
    fclose(fp);
}
