// 修改题目2中的程序，增加异常处理机制，以便在new[]分配
// 内存失败时捕获std::bad_alloc异常，并打印一条错误消息
#include <iostream>
#include <new>

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
    try {
        Human* ptr{
            new Human[5]{{"bitofux", 20}, {"tofu", 21}, {"alice", 22}, {"bob", 23}, {"wang", 24}}};
        for (int i = 0; i < 5; i++) {
            ptr[i].show();
        }
        delete[] ptr;
    } catch (std::bad_alloc& ref) {
        std::cout << "内存分配失败\n";
    }

    std::cout << "程序继续执行..\n";
    return 0;
}
