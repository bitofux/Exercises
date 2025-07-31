// 编写一个函数，该函数接收一个Color枚举类型的参数，并根据
// 参数值打印出对应的颜色名称
#include <iostream>

enum class Color { RED, GREEN, BLUE };

void enumFunc(Color enum_var) {
    int number = static_cast<int>(enum_var);
    switch (number) {
        case 0: {
            std::cout << "RED\n";
            break;
        }
        case 1: {
            std::cout << "GREEN\n";
            break;
        }
        case 2: {
            std::cout << "BLUE\n";
            break;
        }
    }
}
int main() {
    Color color{Color::BLUE};

    enumFunc(color);

    return 0;
}
