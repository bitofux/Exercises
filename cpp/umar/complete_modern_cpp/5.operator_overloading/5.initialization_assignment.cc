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
    Product(const Integer& id)
        : id_{id} {
        std::cout << "Product(const Integer&)" << std::endl;
        // id_ = id;
    }
    ~Product() { std::cout << "~Product()" << std::endl; }

    const Integer& GetInteger() const { return id_; }

    // 类型转换操作符
    // operator Integer() { return id_; }

    friend class Integer;
};

Integer::Integer(const Product& other)
    : ptr_{new int{other.id_.GetValue()}} {
    std::cout << "Integer(const Product&)" << std::endl;
}

int main() {
    Product p{5};
    Integer id = p;

    if (id == p.GetInteger()) {
        std::cout << "id  == p" << std::endl;
    }

    return 0;
}
