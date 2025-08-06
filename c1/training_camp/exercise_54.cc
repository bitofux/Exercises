// 定义一个inline函数add,该函数接收两个整数参数并返回它们的和
// 在main函数中调用add函数，并打印结果
#include <iostream>
inline int add(int a, int b) { return a + b; }
int main() {
    std::cout << add(3, 5) << '\n';

    return 0;
}
