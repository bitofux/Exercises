// 编写一个C++程序，定义一个带有const修饰的成员函数的类，该函数返回指向内部成员的const指针，然后在主函数中
// 通过const_cast去除const属性，并修改该成员的值
#include <iostream>

class Human {
public:
    Human(const std::string name, const int age)
        : name_{name},
          age_{age} {
        std::cout << "Human(const std::string,const int)\n";
    }

    const int* get_age_pointer() const { return &age_; }
    int get_age() const { return age_; }

private:
    std::string name_;
    int age_;
};

int main() {
    Human h1{"bitofux", 20};
    std::cout << h1.get_age() << '\n';

    int* ptr_age{const_cast<int*>(h1.get_age_pointer())};
    *ptr_age = 23;
    std::cout << h1.get_age() << '\n';

    return 0;
}
