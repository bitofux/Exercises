// 扩展题目1中的Human类，编写一个C++程序，使用new[]操作符动态分配一个包含5个Human对象的数组
// 并通过指针数组遍历并打印每个Point对象的x和y值，最后使用delete[]操作符释放该数组
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
    Human* ptr{
        new Human[5]{{"bitofux", 20}, {"tofu", 21}, {"alice", 22}, {"bob", 23}, {"wang", 24}}};

    for (int i = 0; i < 5; i++) {
        ptr[i].show();
    }

    delete[] ptr;

    return 0;
}
