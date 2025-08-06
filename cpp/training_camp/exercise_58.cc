// 1.声明一个指向const整数的指针,并通过该指针初始化一个整数
// 2.尝试通过指针修改其指向的值，确保编译器报错
// 3.声明一个指针常量，并初始化它指向一个整数
// 尝试修改指针常量的值(即让它指向另一个地址)，确保编译器报错

int main() {
    int var = 10;
    // 1.指向常量的指针
    const int* ptr_val = &var;
    // *ptr_val = 20;  // error

    // 2.指针常量(本身不可修改)
    int num = 20;
    int* const p_var = &var;
    // p_var = &num;//error
    return 0;
}
