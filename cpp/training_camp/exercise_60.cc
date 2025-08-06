// 1.编写一个类，其中包含至少一个成员变量和一个const成员
// 函数,const成员函数应保证不修改类的任何成员变量
//(除了mutable修饰的变量)
// 2.在main函数中创建该类的对象，并调用const成员函数
// 验证其不会修改对象的状态
#include <iostream>
#include <string>
class Base {
public:
    Base() = default;
    Base(const std::string name = " ", const int age = -1)
        : name_{name},
          age_(age) {}

    void test() const {
        name_ = "test";  // can modify
        // age_ = 20; //cant modify
    }
    void show() const { std::cout << "name: " << name_ << ", age: " << age_ << '\n'; }

private:
    mutable std::string name_;
    int age_;
};

int main() {
    Base base{"bitofux", 20};
    base.test();
    base.show();

    return 0;
}
