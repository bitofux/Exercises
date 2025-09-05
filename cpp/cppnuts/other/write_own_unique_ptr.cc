/****************************************************
 * @file    write_own_unique_ptr.cc
 * @brief   编写一个简易的unique_ptr模板类
 * @author  bitofux
 * @date    2025-09-01
 ****************************************************/
#include <algorithm>
#include <iostream>

template <typename T>
class UniquePointer {
private:
    T* ptr_;

public:
    // 构造函数
    explicit UniquePointer(T* ptr)
        : ptr_{ptr} {
        std::cout << "Constructor called\n";
    }

    // 析构函数
    ~UniquePointer() {
        delete ptr_;
        std::cout << "Destructor called\n";
    }

    // 禁用拷贝构造和拷贝赋值函数
    UniquePointer(const UniquePointer&) = delete;
    UniquePointer& operator=(const UniquePointer&) = delete;

    // 使用移动构造和移动赋值函数来转移所有权
    UniquePointer(UniquePointer&& other) noexcept
        : ptr_{other.ptr_} {
        std::cout << "Move constructor called\n";
        ptr_ = nullptr;
    }
    UniquePointer& operator=(UniquePointer&& other) noexcept {
        std::cout << "Move assignment called\n";
        if (this != &other) {
            delete ptr_;        // clean up current resource
            ptr_ = other.ptr_;  // take owenship;
            other.ptr_ = nullptr;
        }
        return *this;
    }

    // 重载-> *操作符
    T* operator->() { return ptr_; }
    const T* operator->() const { return ptr_; }

    T& operator*() { return *ptr_; }
    const T& operator*() const { return *ptr_; }

    // 重载bool类型 检查是否为空
    operator bool() noexcept { return (ptr_ != nullptr); }
};

// 测试类
class Demo {
public:
    Demo() { std::cout << "Demo created\n"; }
    ~Demo() { std::cout << "Demo destroyed\n"; }
    void hello() { std::cout << "Hello from Demo!\n"; }
};

void test() {
    std::cout << "=== Move Constructor Example ===\n";
    UniquePointer<Demo> demo1{new Demo{}};
    UniquePointer<Demo> demo2{std::move(demo1)};

    if (!demo1) {
        std::cout << "demo1 is empty!" << std::endl;
    }

    if (demo2) {
        std::cout << "demp2 is not empty!" << std::endl;
    }

    std::cout << "=== Move Assignment Example ===\n";
    UniquePointer<Demo> demo3{new Demo()};
    UniquePointer<Demo> demo4{new Demo()};
    demo3 = std::move(demo4);

    if (!demo4) {
        std::cout << "demo4 is empty!" << std::endl;
    }

    std::cout << "\n=== End of main ===\n";
}

int main() {
    test();

    return 0;
}
