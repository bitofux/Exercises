// 定义一个简单的类StringWrapper，该类包含一个std::string
// 成员变量。为这个类实现一个移动构造函数，使得当
// 用右值初始化或赋值给StringWrapper对象时，能够利用移动语义来避免不必要的字符串拷贝
#include <iostream>

class StringWrapper {
public:
    StringWrapper(const std::string name)
        : name_{name} {
        std::cout << "StringWrapper(const std::string)\n";
    }
    // 移动构造函数
    StringWrapper(StringWrapper&& other)
        : name_(other.name_) {
        other.name_ = " ";
        std::cout << "Move Constructors: StringWrapper(StringWrapper&&)\n";
    }
    // 移动赋值函数
    StringWrapper& operator=(StringWrapper&& other) {
        if (this != &other) {
            name_ = other.name_;
            other.name_ = " ";
        }
        std::cout << "Move Assignment: StringWrapper(StringWrapper&&)\n";
        return *this;
    }
    ~StringWrapper() { std::cout << "~StringWrapper()\n"; }
    void show() const { std::cout << "name: " << name_ << '\n'; }

private:
    std::string name_;
};

int main() {
    StringWrapper sw1{"tofu"};
    sw1.show();

    // 使用纯右值初始化sw2 -> 移动构造函数
    StringWrapper sw2{StringWrapper{"bitofux"}};
    sw2.show();

    std::cout << "移动前sw1,sw2的值: \nsw1.";
    sw1.show();
    std::cout << "sw2.";
    sw2.show();
    // 利用移动语义使得sw1的资源所有权可被"窃取"
    sw1 = std::move(sw2);

    std::cout << "移动后sw1,sw2的值: \nsw1.";
    sw1.show();
    std::cout << "sw2.";
    sw2.show();

    return 0;
}
