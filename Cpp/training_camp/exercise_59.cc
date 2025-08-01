// 1.编写一个函数，其参数为const引用，用于输出参数的值但不能修改它
// 2.编写一个函数，其返回值为const指针，指向一个静态或全局变量，确保返回的指针指向的内容不能被修改

#include <iostream>

namespace {
void constPar(const int& ref) {
    // ref = 20;//error
    std::cout << ref << '\n';
}

const int* returnPointer() {
    static int var = 30;
    return &var;
}
}  // namespace

int main() {
    int var = 20;
    constPar(var);

    std::cout << *returnPointer() << '\n';

    return 0;
}
