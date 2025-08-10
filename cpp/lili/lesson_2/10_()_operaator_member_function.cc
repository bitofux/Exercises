//()运算符重载，使用重载了()运算符
// 的类类型定义的对象称为函数对象
#include <iostream>

class FuncObject {
public:
    FuncObject()
        : count_{0} {}

    // 重载()运算符的函数
    int operator()(int x, int y) {
        ++count_;
        return x + y;
    }
    int operator()(int x, int y, int z) { return x + y + z; }

private:
    int count_;
};
int add(int x, int y) { return x + y; }
int add(int x, int y, int z) { return x + y + z; }
void test() {
    FuncObject fo{};

    // 函数对象
    std::cout << "fo(10,5): " << fo(10, 5) << '\n';
    std::cout << "fo(10,5,2): " << fo(10, 5, 2) << '\n';

    // 普通函数
    std::cout << "add(10,5): " << add(10, 5) << '\n';
    std::cout << "add(10,5,2): " << add(10, 5, 2) << '\n';

    // 使用函数指针
    using pFunc2 = int (*)(int, int);
    using pFunc3 = int (*)(int, int, int);
    pFunc2 pf1{add};
    pFunc3 pf2{add};
    std::cout << "pf1(10,5): " << pf1(10, 5) << '\n';
    std::cout << "pf2(10,5,2): " << pf2(10, 5, 2) << '\n';
}

int main() {
    test();

    return 0;
}
