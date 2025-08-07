// 编写一个程序，定义一个函数findMax,该函数接收两个任意类型
//(使用模板)的参数(假设这些类型支持比较操作)，并使用auto
// 关键字自动推导返回类型，返回这两个参数的较大值

#include <iostream>

class Cat;
class Dog {
public:
    Dog(const int age)
        : age_{age} {}
    int get_age() const { return age_; }

private:
    friend bool operator>(const Dog& lhs, const Cat& rhs);
    friend bool operator>(const Cat& lhs, const Dog& rhs);

private:
    int age_;
};

class Cat {
public:
    Cat(const int age)
        : age_{age} {}
    int get_age() const { return age_; }

private:
    friend bool operator>(const Dog& lhs, const Cat& rhs);
    friend bool operator>(const Cat& lhs, const Dog& rhs);

private:
    int age_;
};

bool operator>(const Dog& lhs, const Cat& rhs) {
    if (lhs.age_ > rhs.age_) {
        return true;
    } else {
        return false;
    }
}
bool operator>(const Cat& lhs, const Dog& rhs) {
    if (lhs.age_ > rhs.age_) {
        return true;
    } else {
        return false;
    }
}

template <typename T, typename U>
auto findMax(const T& lhs, const U& rhs) {
    if (lhs > rhs) {
        return lhs.get_age();
    }

    return rhs.get_age();
}
int main() {
    Dog d1{20};
    Cat c1{30};

    std::cout << findMax(d1, c1) << '\n';

    return 0;
}
