/*
 * PROJECT : EXERCISES
 * FILE    : 2.inherit_intro.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-07-08
 * BRIEF   : 单继承的介绍
 */
#include <iostream>

// 继承之后的访问控制一定要区分类外和类内
namespace pub_inherit {
class Animal {
public:
    void pub_func() { std::cout << "pub_func" << std::endl; }

protected:
    void pro_func() { std::cout << "pro_func" << std::endl; }

private:
    void pri_func() { std::cout << "pri_func" << std::endl; }
};

class Dog : public Animal {  // 在Dog类内，Animal类中的成员的访问控制是无变化的
public:
    // 类内
    void access() {
        pub_func();  // can access
        pro_func();  // can access
        // pri_func(); // cant access
    }
};

void test_dog() {
    // 类外
    Dog dog;
    dog.pub_func();  // can access
    // dog.pro_func(); // cant access
    // dog.pri_func(); // cant access
}
}  // namespace pub_inherit
namespace pro_inherit {
class Animal {
public:
    void pub_func() { std::cout << "pub_func" << std::endl; }

protected:
    void pro_func() { std::cout << "pro_func" << std::endl; }

private:
    void pri_func() { std::cout << "pri_func" << std::endl; }
};

class Dog
    : protected Animal {  // 在Dog类内，Animal类中的成员的访问控制是有变化的，无public，public自动变成protected
public:
    // 类内
    void access() {
        pub_func();  // can access
        pro_func();  // can access
        // pri_func(); // cant access
    }
};

void test_dog() {
    // 类外
    Dog dog;
    // dog.pub_func();// cant access
    // dog.pro_func(); // cant access
    // dog.pri_func(); // cant access
}
class Ldog
    : protected Dog {  // 由于Animal类中数据成员在Dog类发生了变化，所以在孙子类Ldog继承Dog后，再次访问Animal的数据
                       // 成员，此时看的是Dog类内的访问限定符，也就是pub_func和pro_func都是protected
public:
    void access() {  // 隐藏父类的access
        pub_func();  // can access
        pro_func();  // can access 因都是protected，子类可以访问父类
        // pri_func();  // cant access 不可以
    }
};
}  // namespace pro_inherit
namespace pri_inherit {
    class Animal {
        public:
            void pub_func() {
                std::cout << "pub_func" << std::endl;
            }
        protected:
            void pro_func() {
                std::cout << "pro_func" << std::endl;
            }
        private:
            void pri_func() {
                std::cout << "pri_func" << std::endl;
            }
    };

    class Dog:private Animal {// 在Dog类内，Animal类中的成员的访问控制是有变化的，且Animal类的数据成员在Dog的访问限定符都
                              // 变成了private，但是要记住，Dog还是Animal的子类，它还是可以访问Animal类中protected权限以上
                              // 的数据成员的，访问控制限定符的变化只是为了限制其他类，以及类外
        public:
            // 类内
            void access() {
                pub_func(); // can access
                pro_func(); // can access
                // pri_func(); // cant access
            }
    };

    void test_dog() {
        // 类外
        Dog dog;
        // dog.pub_func();// cant access
        // dog.pro_func(); // cant access
        // dog.pri_func(); // cant access
    }
    // 孙子类也是一样被限制
    class Ldog:public Dog { // 即使你是public继承Dog，一样在类内和类外访问不了Animal中的任何数据成员，因为它的父类Dof中
                            // Animal的三个成员函数都被private这个访问控制限定符修饰着
        public:
            void access() {
                // pub_func(); // cant access;
                // pro_func() ; // cant access
                // pri_func(); // cant access
            }

    };
}

int main() {

}
