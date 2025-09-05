/****************************************************
 * @file    03_test.cc
 * @brief   fork函数
 * @author  bitofux
 * @date    2025-09-02
 ****************************************************/
#include <cstdio>
#include <iostream>
#include <unistd.h>

int main() {
    auto pid = fork();

    int n;
    if (pid == 0) {
        n = 1;
    } else {
        int status;
        wait(&status);
        n = 6;
    }

    for (int i = n; i < n + 5; i++) {
        std::cout << i;
        std::fflush(stdout);
    }

    std::cout << "\n";

    return 0;
}
