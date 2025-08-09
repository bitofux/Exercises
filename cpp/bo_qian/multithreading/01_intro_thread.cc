#include <iostream>
#include <thread>

void func() { std::cout << "Beauty is only skin-deep\n"; }
int main() {
    // 以func为参数创建一个thread类对象
    std::thread t1{func};  // t1 starts running

    // t1.join() -> 主线程等待子线程执行完成

    // t1.detach(); 子线程脱离主线程独自执行
    // 与主线程并发执行 但是它仍然与主线程属于同一个进程
    // 当主线程执行完毕代表进程终止,那么它也会终止
    // 称datch的自线程为daemon thread可能会合适一些
    // 值得注意的是，如果是主线程执行完毕进程终止，那么
    // 共享资源(文件，堆等)也会被回收，其实这时候子线程
    // 也直接终止了
    t1.detach();

    // 判断子线程t1是否可join
    if (t1.joinable()) {
        t1.join();
    }

    return 0;
}
