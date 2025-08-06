/*定义一个基类Base（使用class或struct均可），它包含一个public的整型成员变量。然后定义一个派生类Derived，它继承自Base，但不修改继承方式（默认继承）。在main函数中创建Derived类的对象，并尝试访问基类中的成员变量。*/

#include <iostream>

class Base {
public:
    int age_;
};

class Derived : public Base {};

struct human {
public:
    int age_;
};

struct man : human {};

int main() {
    Derived d1;
    // 子类derived默认私有继承自Base,子类对象不可以访问基类中的公有成员,除非显示public继承
    std::cout << d1.age_ << std::endl;

    man m1;
    // struct默认时public继承，可以访问
    std::cout << m1.age_ << std::endl;
    return 0;
}
