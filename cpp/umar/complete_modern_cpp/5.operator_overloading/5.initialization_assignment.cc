/*
 * PROJECT : EXERCISES
 * FILE    : 5.initialization_assignment.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-10-18
 * BRIEF   : 初始化与赋值
 */

#include <iostream>

#include "integer.hpp"

class Product {
private:
    Integer id_;

public:
    Product(const Integer& id) {
        std::cout << "Product(const Integer&)" << std::endl;
        id_ = id;
    }
    ~Product() { std::cout << "~Product()" << std::endl; }
};

int main() { Product p{5}; }
