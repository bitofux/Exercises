// class与struct的默认访问权限
// 要求：定义一个class和一个struct，它们各自包含一个整型成员变量和一个成员函数用于设置该变量的值。在main函数中创建这两个类型的对象，并尝试从类外部直接访问它们的成员变量。观察编译器的行为并解释原因。
#include <iostream>

class human {
    int age_;
    void setAge(int age) {
        age_ = age;
    } 
};

struct student {
    int age_;
    void setAge(int age) {
        age_ = age;
    }
};

int main() {
    human h1;
    std::cout << h1.age_ << std::endl;

    student s1;
    std::cout << s1.age_ << std::endl;

    return 0;
}
