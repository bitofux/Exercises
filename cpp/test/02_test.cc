/****************************************************
 * @file    02_test.cc
 * @brief   测试左值引用和右值引用的所有权 
 * @author  bitofux
 * @date    2025-08-25
 ****************************************************/
#include <iostream>


int main() {
    int a {10};

    {
        auto& ref {a};
        ref = 20;
        std::cout << "ref: " << ref << std::endl;
    }

    std::cout << "a: " << a << std::endl;
}
