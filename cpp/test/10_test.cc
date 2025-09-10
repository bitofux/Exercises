#include <cstring>
#include <iostream>
using std::cout;

// 这就是一个函数模板
template <typename T>  // 模板参数列表 T是类型参数
bool compare(T a, T b) {
    cout << "compare\n";
    return a < b;
}

// 模板实例化
//  bool compare<int>(int a,int b) {
//      cout << "compare\n";
//      return a < b;
//  }

// bool compare<double>(double a,double b) {
//     cout << "compare\n";
//     return a < b;
// }

// 函数模板的特例化 -- 专门为某个类型进行实例化
template <>
bool compare<const char*>(const char* a, const char* b) {
    cout << "compare<const char*,const char*>\n";
    return std::strcmp(a, b) < 0;
}

// 普通函数
bool compare(const char* a, const char* b) {
    cout << "normal function\n";
    return a < b;
}
int main() {
    // 函数模板的调用点
    // 从这里编译器会根据用户传入类型参数实例化一个
    // 模板函数，这是在编译阶段做的事情，并为此生成函数符号
    compare<int>(10, 20);
    compare<double>(10.2, 20.2);

    // 编译器还会根据你传入的实际参数进行类型推导，使用推导后的类型
    // 进行模板实例化，生成函数符号
    compare(2.2f, 3.3f);

    // 但如果你传入的两个实际参数的类型不一样，编译器会报错
    // 因为不知道该使用哪个实际参数的类型进行实例化
    // 1.指定类型 2.在函数模板的模板参数列表中添加第二个类型参数
    compare<int>(10, 20.2);  // 会将double类型的20.2转换为int
    // 当函数模板、函数模板特例化、普通函数共同存在的时候
    // 普通函数 -> 函数模板特例化 -> 函数模板
    compare("aaa", "bbb");

    return 0;
}
