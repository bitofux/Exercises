#include "sys_header.h"
int main(int argc, char** argv) {
    if (argc < 3) {
        fprintf(stderr, "usage: exec ip port\n");
        return -1;
    }

    // 创建一个socket类型的文件对象
    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd < 0) {
        error(1, errno, "socket");
    }

    // 用户态创建一个用户保存ip和端口的对象,
    // 用于传给内核态 这是服务器的地址和端口信息
    struct sockaddr_in addr_in;
    // 地址类型
    addr_in.sin_family = AF_INET;
    // 大端表示的端口
    addr_in.sin_port = htons(atoi(argv[2]));
    // 大端表示的ip
    addr_in.sin_addr.s_addr = inet_addr(argv[1]);

    // 客户端没太多必要绑定ip+port，使用随机的端口即可

    // 连接服务器 发起三次握手
    int ret_conn = connect(sock_fd, (struct sockaddr*)&addr_in, sizeof(addr_in));
    if (ret_conn < 0) {
        error(1, errno, "connect");
    }

    // 创建用户态缓冲区保存读取到的数据
    char buf[1024] = {0};
    // 给服务器发送数据
    int ret_send = send(sock_fd, "hello", 5, 0);
    if (ret_send < 0) {
        error(1, errno, "send");
    }
    // 读取服务器发送的数据
    int ret_recv = recv(sock_fd, buf, sizeof(buf), 0);
    if (ret_recv < 0) {
        error(1, errno, "recv");
    }

    // 将服务器的数据发送到console
    int ret_write = write(STDOUT_FILENO, buf, sizeof(buf));
    if (ret_write < 0) {
        error(1, errno, "write");
    }

    return 0;
}
