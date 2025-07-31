// 编写一个C语言程序，定义一个函数int add(int a,int b)
// 该函数返回两个整数的和，然后定义一个函数指针变量pAdd
// 将其指向add函数，并通过pAdd调用add函数，计算并打印3和5的和

#include <iostream>

int add(int a, int b) { return a + b; }
int main() {
    int (*pAdd)(int, int) = add;

    // 函数指针调用函数
    std::cout << pAdd(3, 5) << '\n';

    return 0;
}
