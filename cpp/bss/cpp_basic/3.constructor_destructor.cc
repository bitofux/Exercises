/*
 * PROJECT : EXERCISES
 * FILE    : 3.constructor_destructor.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-02-11
 * BRIEF   : 构造函数和析构函数
 */

#include <iostream>
#include <string>

/*构造函数:
 * 1. 构造对象
 * 2. 初始化对象中的数据成员
 * 3. 类型转换*/

/*析构函数:
 * 1. 销毁对象中数据成员
 * 2. 销毁一个对象*/

// 构造与析构的过程就是入栈和出栈的过程顺序
class Human {
public:
    // 无参构造函数
    Human() { std::cout << "Human::Human(),object address: " << this << "\n"; }
    // 单个参数的构造函数，可用于其他类型转换到Human类型
    explicit Human(int age) { std::cout << "Human::Human(int),object address: " << this << "\n"; }
    // 两个参数的构造函数
    Human(std::string name, int age) {
        std::cout << "Human::Human(std::string,int),object address: " << this << "\n";
    }
    operator int() {
      std::cout << "Human -> int\n";
      return _age;
    }
    // 析构函数
    ~Human() { std::cout << "~Human(),object address: " << this << "\n"; }

private:
    std::string _name;
    int _age;
};

int main() {
    // 1. 利用多个构造函数构造多个对象
    Human h1{};
    Human h2{20};
    Human h3{"bitofux", 20};
    // 2. 隐式类型转换
    // Human h4 = 21; // 牢记临时对象的概念，转换的目的是将21这个int类型的数据转换为Human类型
                   // 那么就会先产生一个Human类型的临时对象，也就是构造一个临时对象
                   // 这时候编译器就会将21这个数据当作构造函数的参数去寻找单个参数的构造函数来
                   // 构造这个临时对象，若没有这个单个参数的构造函数，则不会构造成功，那么就转换
                   // 失败。构造成功之后，还会调用拷贝构造函数完成一个Human类型的对象到另外一个
                   // 对象的构造
                   // 若不想发生隐式转换，则需要在特定的构造函数前加上explicit关键字，想要发生
                   // 转换则需要强制转换
    Human h5 = static_cast<Human>(22);

    // 3. 从Human类型转换到int类型
    int age = h2; // h2到age的类型转换，也是需要一个int类型的临时变量，在Human的类中就需要定义
                  // 类似这样的函数    operator int() { return _age;}


    return 0;
}
