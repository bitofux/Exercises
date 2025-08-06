/*编写一个C++程序，其中包含两个重载函数show，一个接受int类型的参数，另一个接受float类型的参数。然后，尝试编写一个函数调用show，其参数在编译时可能既可以是int类型也可以是float类型（例如，使用字面量3.0，但没有明确的小数点或类型后缀），并解释如何修改这个调用以避免编译器的重载歧义错误。*/

#include <iostream>

void show(int num) {
    std::cout << "num: " << num << "\n";
}

void show(float var) {
    std::cout << "var: " << var << "\n";
}

int main() {
    //4.0是一个double类型字面量,既可以转换为int也可以转换为float,因此这里出现了二义性
    // show(4.0);

    //1. 使用静态转换
    show(static_cast<int>(4.0));//调用show(int)
    show(static_cast<float>(4.0));//调用show(float)

    //2. 使用f后缀直接使浮点数是float类型
    show(4.0f);

    return 0;
    
}
