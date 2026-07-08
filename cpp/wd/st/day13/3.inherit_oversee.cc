/*
 * PROJECT : EXERCISES
 * FILE    : 3.inherit_oversee.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-07-08
 * BRIEF   : 继承下的隐藏
 */
#include <iostream>

namespace object_size {
class Human {
private:
    double hm_data_;
};

class Man : public Human {
private:
    double m_data_;
};

// 子类对象大小
void test() {
    Man m1;
    std::cout << "m1 size: " << sizeof(m1) << std::endl;
}
}  // namespace object_size

namespace over_see {
class Human {
public:
    Human()
        : age_{10},
          human_salary_{20.2} {}
    void show() const { std::cout << "human::show()" << std::endl; }
    int age_;
    double human_salary_;
};

class Man : public Human {
public:
    Man()
        : age_{20},
          man_salary_{10.2},
          Human{} {}
    // using Human::age_; // 不会产生重定义，但是在访问的时候会产生二义性
    int show() const{
        std::cout << "man::show()" << std::endl;
        return 1;
    }
    int age_;
    double man_salary_;
};

// 测试数据成员的隐藏
void test() {
    Man m1;

    // 访问age_数据成员，查看输出哪个
    std::cout << m1.age_ << std::endl;  // Man中的age_数据成员
}

// 测试成员函数的隐藏
// 成员函数只要派生类与父类的成员函数名称相同，就构成隐藏，与返回值与参数类型无关
// 若在派生类中使用using Human::show，那么就位于在一个作用域可见，若名称相同，对应参数类型不同，会构成重载，与返回值无关
void test_func() {
    Man m1;
    m1.show();
}
};  // namespace over_see

int main() {
    // object_size::test();
    // over_see::test();
    over_see::test_func();

    return 0;
}
