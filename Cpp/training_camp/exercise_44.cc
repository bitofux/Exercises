/*指针的大小通常是固定的，对于32位系统，其大小为几个字节；对于64位系统，其大小为几个字节*/
#include <iostream>

int main() {
    std::cout << sizeof(void*) << std::endl;

    return 0;
}
