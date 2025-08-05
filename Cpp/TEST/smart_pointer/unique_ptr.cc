#include <iostream>

class human {
private:
    std::string name_;
    int age_;

public:
    human(const std::string name, const int age)
        : name_{name},
          age_{age} {
        std::cout << "human(const std::string,const int)\n";
    }
    ~human() { std::cout << "~human()\n"; }
};
int main() {
    // 使用new
    //  基本类型
    auto p = std::unique_ptr<int>{new int{20}};

    auto d{std::unique_ptr<double>{new double{20.22}}};

    std::cout << p.get() << ' ' << *p << '\n';
    std::cout << d.get() << ' ' << *d << '\n';

    // 类类型
    auto ptr{std::unique_ptr<human>{new human{"bitofux", 32}}};
    std::cout << ptr.get() << '\n';

    // 使用make_unique
    // 基本类型
    auto ptr_int{std::make_unique<int>(10)};
    std::cout << ptr_int.get() << ' ' << *ptr_int << '\n';

    // 类类型
    auto ptr_human{std::make_unique<human>("bitofux", 23)};
    std::cout << ptr_human.get() << '\n';

    return 0;
}
