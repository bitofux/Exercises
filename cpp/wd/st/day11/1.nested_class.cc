/*
 * PROJECT : EXERCISES
 * FILE    : 1.nested_class.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-06-27
 * BRIEF   : 嵌套类
 */
#include <iostream>

using std::cout;
using std::endl;

class outer {
public:
    // 测试outer内访问内部类的数据成员
    void test1() {
        // public
        inner1 ier;
        ier.inner1_data_ = 20;  // ok
        ier.inner1_private_data_ =
            30;  // error ,test1对于inner1类属于外部，不可访问，除非将inner1设置为友元类，或者
                 // 将这个成员函数设置为友元函数

        // private
        inner2 ier1;
        ier1.inner2_data_ = 30;
        ier1.inner2_private_data_ = 40;  // error ，同上
    }

public:
    class inner1 {
        // 测试内部类访问外部类的数据成员 要记住：内部类在C++11之后天然就是外部类的友元类
        void test2() {
            outer oer;
            oer.test1();           // ok
            oer.outer_data_ = 50;  // ok
        }

    public:
        int inner1_data_;

    private:
        int inner1_private_data_;
        friend void test();
        friend void outer::test1();
    };

private:
    class inner2 {
    public:
        int inner2_data_;

    private:
        int inner2_private_data_;
        friend void outer::test1();
    };

    // 数据成员
    int outer_data_;
    friend void test();
};

// 1.  测试在outer类外访问不同权限下的实体
void test() {
    // public权限
    outer::inner1 ier1;  // OK
    // private权限
    outer::inner2 ier2;  // error 不可访问private下的实体,除非将这个函数设置为outer类的友元函数

    // 测试内部类对象访问内部类的实体
    ier1.inner1_data_ = 10;  // OK
    ier1.inner1_private_data_ =
        20;  // error 不可访问内部类inner1中的private成员，除非将这个函数设置为inner1的友元函数
    // inner2同理
}

int main() {
    test();

    return 0;
}
