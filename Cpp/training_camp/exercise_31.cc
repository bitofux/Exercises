/*编写一个C++程序，包含三个重载版本的print函数，分别接受int、double和const
 * char*类型的参数，并分别输出其值。在主函数中调用这三个重载版本的print函数。*/

#include <iostream>

namespace bitofux {
void print(int number) { std::cout << "number: " << number << "\n"; }
void print(double dou) { std::cout << "dou: " << dou << "\n"; }
void print(const char* ptr) { std::cout << "ptr: " << ptr << "\n"; }
}  // namespace bitofux

int main() {
    using bitofux::print;

    print(10);
    print(20.22);
    print("bitofux");

    return 0;
}
