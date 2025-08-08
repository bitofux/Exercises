// 编写一个C++程序，定义一个基类Base和一个派生类Derived
// 其中Derived类有一个额外的成员变量。在主函数中，创建一个
// Derived对象，并使用static_cast将Derived*转换为Base*,
// 然后通过这个基类指针访问派生类共有的成员变量(有的话)
// 接着，尝试(但不应成功)使用static_cast将Base*转换为
// Derived*(因为这里缺少类型信息，应该使用dynamic_cast
// 或确保转换是安全的)
#include <iostream>

class Base {
public:
    Base() = default;
    Base(const int var)
        : var_{var} {
        std::cout << "Base(const int)\n";
    }
    // 添加一个虚函数，使其有运行时类型信息
    virtual int get() const { return var_; }

private:
    int var_;
};

class Derived : public Base {
public:
    int get_age() const { return age_; }

private:
    int age_;
};

int main() {
    Derived d1;
    // 将子类指针转换基类指针(允许)
    Base* ptr{static_cast<Base*>(&d1)};

    // 只能访问Base中的成员
    std::cout << ptr->get() << '\n';

    Derived* der{static_cast<Derived*>(ptr)};
    std::cout << der->get_age() << '\n';

    // Base b1{20};
    //  编译可过 但使用指针会出现UB，因为b1本就是一个Base
    //  类型的对象
    //  Derived* ptr_derived {static_cast<Derived*>(&b1)};
    Derived d2;
    // 向上转型
    Base* ptr_base{&d2};
    std::cout << ptr_base->get() << '\n';

    // 将其转换回Derived*类型 ok
    Derived* ptr_derived = dynamic_cast<Derived*>(ptr_base);
    return 0;
}
