/*定义一个Person类，包含姓名（name）和年龄（age）作为私有成员变量，以及相应的构造函数、析构函数、设置和获取成员变量的成员函数。在main函数中创建Person对象，并测试这些成员函数。*/
#include <iostream>

class Person {
public:
    Person() { std::cout << "Person()\n"; }
    ~Person() { std::cout << "~Person(\n)"; }

public:
    void setName(const std::string name) { this->name_ = name; }
    std::string getName() const { return this->name_; }

    void setAge(const int age) { this->age_ = age; }

    int getAge() const { return this->age_; }

private:
    std::string name_;
    int age_;
};

int main() {
    Person p1;
    p1.setName("wangshuai");
    p1.setAge(20);

    std::cout << "name: " << p1.getName() << "\n";
    std::cout << "age: " << p1.getAge() << "\n";

    return 0;
}
