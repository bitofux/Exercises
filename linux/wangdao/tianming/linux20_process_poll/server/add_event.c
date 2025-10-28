#include "header.h"
#include <sys/epoll.h>

void add_event(int ep, int fd, uint32_t events) {
    struct epoll_event ev = {.data.fd = fd, .events = events};
    epoll_ctl(ep, EPOLL_CTL_ADD, fd, &ev);
}
