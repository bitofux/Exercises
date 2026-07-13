/*
 * PROJECT : DAY14
 * FILE    : 2.poly_intro.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-07-13
 * BRIEF   : 多态的介绍
 */
#include <cstdint>
#include <iostream>
#include <string>

class Animal {
public:
    Animal(std::string name = "")
        : name_{name} {
        std::cout << "Animal(std::string)\n";
    }

    // 纯虚函数
    virtual void say() const = 0;

private:
    std::string name_;
};

class Dog : public Animal {
public:
    Dog(std::string name)
        : Animal{name} {}
    void say() const { std::cout << "汪汪汪\n"; }
};

class Cat : public Animal {
public:
    Cat(std::string name)
        : Animal{name} {}
    void say() const { std::cout << "喵喵喵\n"; }
};

void test(const Animal& animal) { animal.say(); }

// 输出各个虚函数所在的内存空间
void print(Animal& animal) {
    uint64_t ptr = *((uint64_t*)(&animal));

    using func_say = void (*)();

    func_say func = (func_say)(*((uint64_t*)ptr));

    func();

    std::cout << "ptr: " << ptr << std::endl;
}

int main() {
    Dog dog{"cc"};
    // test(dog);
    print(dog);
    Cat cat{"hh"};
    // test(cat);
    print(cat);

    return 0;
}
