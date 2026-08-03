#include <sys/epoll.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <cstring>
#include <cstdio>

// 设置fd为非阻塞
int make_nonblock(const int fd) {
    // 获取当前fd的标志
    int flags = fcntl(fd, F_GETFL, 0);
    // 将当前fd的标志添加一个O_NONBLOCK
    (void)fcntl(fd, F_SETFL, flags | O_NONBLOCK);
    return fd;
}
int main() {
    int lfd = socket(AF_INET, SOCK_STREAM, 0);
    make_nonblock(lfd);

    sockaddr_in addr{};
    addr.sin_family = AF_INET;
    addr.sin_port = htons(8080);
    addr.sin_addr.s_addr = INADDR_ANY;

    int bind_ret = bind(lfd, (sockaddr*)&addr, sizeof(addr));
    if (bind_ret < 0) {
        perror("bind");
        return -1;
    }
    listen(lfd, 128);

    // 创建epoll实例
    int ep = epoll_create1(0);
    // 设置事件源属性
    struct epoll_event ev{};
    ev.events = EPOLLET | EPOLLIN;
    ev.data.fd = lfd;

    // 将事件源添加到实例
    epoll_ctl(ep, EPOLL_CTL_ADD, lfd, &ev);

    // 可读/可写的fd集合,内核会将它们拷贝到用户态
    struct epoll_event events[20];

    // 用户态缓冲区
    char buf[4096];
    memset(buf, 0, sizeof(buf));

    while (true) {
        int n = epoll_wait(ep, events, 64, -1);
        // 若epoll_wait返回则表示监听的事件源满足条件
        for (int i = 0; i < n; ++i) {
            int fd = events[i].data.fd;
            // 若lfd监听到新的连接
            if (fd == lfd) {
                // 立刻调用accept建立一条与客户端完整的tcp连接
                int cfd = accept(fd, nullptr, nullptr);
                make_nonblock(cfd);
                ev.events = EPOLLIN | EPOLLET;
                ev.data.fd = cfd;
                epoll_ctl(ep, EPOLL_CTL_ADD, cfd, &ev);
            } else {
                ssize_t m = recv(fd, buf, sizeof buf, 0);
                if (m > 0) {
                    send(fd, buf, m, 0);
                } else if (m == 0) {
                    close(fd);
                }
            }
        }
    }
}
