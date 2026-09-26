/*
 * PROJECT : EXERCISES
 * FILE    : 3.integer.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-09-25
 * BRIEF   :
 */

#include <iostream>

class Integer {
private:
    int* ptr_;

public:
    Integer() { ptr_ = new int{0}; }
    Integer(int value) { ptr_ = new int{value}; }
    Integer(const Integer& other) { ptr_ = new int{*other.ptr_}; }
    int GetValue() const { return *ptr_; }
    void SetValue(int value) { *ptr_ = value; }
    const int* GetData() const { return ptr_; }
    ~Integer() { delete ptr_; }
};

int main() {
    Integer integer{10};
    std::cout << integer.GetValue() << std::endl;

    Integer integer2{integer};
    std::cout << "integer: " << static_cast<const void*>(integer.GetData()) << "\n";
    std::cout << "integer2: " << static_cast<const void*>(integer2.GetData()) << "\n";
    return 0;
}
