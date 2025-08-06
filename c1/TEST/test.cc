#include <iostream>
#include <exception>
#include <stdexcept>

class Myexcept : public std::exception {
public:
    Myexcept(const std::string name)
        : name_{name} {
        std::cout << "Myexcept(const std::string)" << std::endl;
    }
    Myexcept(const Myexcept&) { std::cout << "Myexcept(const Myexcept&)" << std::endl; }
    const char* what() const noexcept override { return name_.c_str(); }
    ~Myexcept() noexcept { std::cout << "~Myexcept() noexcept" << std::endl; }

private:
    std::string name_;
};
void divFunc(int var1, int var2) {
    if (var2 == 0) {
        throw Myexcept{"这是我的自定义异常"};
    }

    std::cout << var1 / var2;
}
void test() { divFunc(20, 0); }
int main() {
    try {
        test();
    } catch (std::runtime_error&) {
        std::cout << "错误处理完成\n";
    } catch (Myexcept&) {
        std::cout << "自定义的异常类型\n";
    }

    return 0;
}
