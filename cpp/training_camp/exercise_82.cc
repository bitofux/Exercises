//编写一个C++程序，定义两个类Base和Derived，其中Derived
//继承自Base。在主函数中，创建Derived对象并通过基类指针
//访问它，然后使用dynamic_cast将基类指针安全的转换为
//派生类指针，并调用派生类的成员函数。
//如果失败，请输出错误信息
#include <iostream>

class Base {
public:
    virtual void show() {
        std::cout << "Base::show()\n";
    }
private:
    int var;
};

class Derived : public Base {
public:
    void print() const {
        std::cout << "Derived::print()\n";
    }
};

int main() {
    Derived d1;
    Base* ptr {&d1};

    // ptr->print();//error

    Derived* ptr_derived {dynamic_cast<Derived*>(ptr)};
    if (!ptr_derived) {
        std::cout << "转换失败\n";
    }
    
    ptr_derived->print();
    return 0;
}
