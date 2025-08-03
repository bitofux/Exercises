// 编写一个C++程序，定义一个简单的类（例如，Human类，包含x和y两个整型成员变量）
// 使用new操作符动态分配一个Human对象，并通过指针访问其成员变量，最后使用delete操作符释放该对象
#include <iostream>

class Human {
public:
    Human(const std::string name, const int age)
        : name_{name},
          age_{age} {}
    void show() const noexcept { std::cout << "name: " << name_ << ", age: " << age_ << std::endl; }

private:
    std::string name_;
    int age_;
};

int main() {
    Human* ptr{new Human{"bitofux", 20}};

    ptr->show();

    delete ptr;

    return 0;
}
