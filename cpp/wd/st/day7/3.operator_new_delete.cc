/*
 * PROJECT : DAY7
 * FILE    : 3.operator_new_delete.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-06-09
 * BRIEF   : new delete 大概工作流程
 */

#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <string>

void* operator new(size_t size) {
    void* p = malloc(size);

    std::cout << "new->p: " << p << std::endl;
    return p;
}

// void operator delete(void* p) {
//     std::cout << "delete->p: " << p << std::endl;
//     free(p);
// }

// 非POD类型
class Human {
public:
    Human(std::string name, int age)
        : m_name{std::move(name)},
          m_age{age} {
        std::cout << "Human(string,int)" << std::endl;
    }

    // 类内的operator new
    void* operator new(size_t size) noexcept {
        void* p = malloc(size);
        std::cout << "Human::operator new -> p: " << p << std::endl;

        return p;
    }

    // 类内的oprator new[]
    void* operator new[](size_t size) noexcept {
        void* p = malloc(size);
        std::cout << "Human::operator new[] -> p: " << p << std::endl;

        return p;
    }

private:
    std::string m_name;
    int m_age;
};

int main() {
    Human* ptr = new Human{"bitofux", 23};
    std::cout << "ptr: " << (void*)ptr << std::endl;

    Human* ptr_arr = new Human[2]{{"bitofux", 22}, {"apple", 2}};
    std::cout << "ptr_arr: " << (void*)ptr_arr << std::endl;
    return 0;
}
