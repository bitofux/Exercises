//编写一个模板函数forwarder，该函数接受任意类型和数量的
//参数，并使用完美转发将这些参数转发给另一个函数

#include <iostream>

void process(int& var) {
    std::cout << "process(int&) -> var : " << var << '\n';
}
void process(int&& var) {
    std::cout << "process(int&&) -> var : " << var << '\n';
}

template<typename T> 
void forwarder(T&& value) {
    process(std::forward<T>(value));
}

int main() {
    //传入左值
    int var = 10;
    forwarder(var);

    //传入prvalue
    forwarder(56);

    return 0;
}

