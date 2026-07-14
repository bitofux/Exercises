/*
 * PROJECT : DAY14
 * FILE    : 3.virtual_function.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-07-14
 * BRIEF   : 虚函数 虚指针 虚函数表
 */
#include <sys/types.h>
#include <cstdint>
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Human {
public:
    Human(string name, int age)
        : name_{name},
          age_{age} {
        cout << "Human(string,int)" << endl;
    }
    virtual void play() { cout << "Human::play()\n"; }

    virtual void say() { cout << "Human::say()\n"; }

private:
    string name_;
    int age_;
};

class bitofux : public Human {
public:
    bitofux(string name, int age)
        : Human{name, age} {
        std::cout << "bitofux(name,int)" << endl;
    }

    void play() override { cout << "bitofux::play()\n"; }
};

int main() {
    Human h1{"A", 20};
    bitofux b1{"bitofux", 28};
    bitofux c1{"tofu", 29};

    cout << "---- Human ----" << endl;
    cout << "Address of Human::play: " << (void (Human::*)())&Human::play << endl;
    cout << "Address of Human::say: " << (void (Human::*)())&Human::say << endl;
    cout << "Address of Human::play in virtual tabel: " << (uint64_t*)(*((uint64_t*)(&h1))) << "-> "
         << "value: " << (void*)*((uint64_t*)(*((uint64_t*)(&h1)))) << endl;
    cout << "Address of Human::say in virtual tabel: " << ((uint64_t*)(*((uint64_t*)(&h1)))) + 1
         << "-> " << "value: " << (void*)*((uint64_t*)(((uint64_t*)*((uint64_t*)(&h1))) + 1))
         << endl;
    cout << "---- Human ----" << endl;

    cout << "---- bitofux ----" << endl;
    cout << "Address of bitofux::play: " << (void (bitofux::*)())&bitofux::play << endl;
    cout << "Address of bitofux::play: " << (void (bitofux::*)())&bitofux::say << endl;
    cout << "Address of bitofux::play in virtual tabel: " << (uint64_t*)(*((uint64_t*)(&b1)))
         << "-> "
         << "value: " << (void*)*((uint64_t*)(*((uint64_t*)(&b1)))) << endl;
    cout << "Address of bitofux::say in virtual tabel: " << ((uint64_t*)(*((uint64_t*)(&b1)))) + 1
         << "-> " << "value: " << (void*)*((uint64_t*)(((uint64_t*)*((uint64_t*)(&b1))) + 1))
         << endl;
    cout << "---- bitofux ----" << endl;
    cout << "---- tofu ----" << endl;
    cout << "Address of bitofux::play: " << (void (bitofux::*)())&bitofux::play << endl;
    cout << "Address of bitofux::play: " << (void (bitofux::*)())&bitofux::say << endl;
    cout << "Address of bitofux::play in virtual tabel: " << (uint64_t*)(*((uint64_t*)(&c1)))
         << "-> "
         << "value: " << (void*)*((uint64_t*)(*((uint64_t*)(&c1)))) << endl;
    cout << "Address of bitofux::say in virtual tabel: " << ((uint64_t*)(*((uint64_t*)(&c1)))) + 1
         << "-> " << "value: " << (void*)*((uint64_t*)(((uint64_t*)*((uint64_t*)(&c1))) + 1))
         << endl;
    cout << "---- tofu ----" << endl;
}
