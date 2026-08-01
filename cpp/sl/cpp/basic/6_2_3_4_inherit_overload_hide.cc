/****************************************************
 * @file    6_2_3_4_inherit_overload_hide.cc
 * @brief   继承、派生类构造过程
 *          基类以及派生类的成员函数重载
 *          派生类对基类中的数据成员和成员函数进行隐藏
 *          因为作用域不同
 *
 *          理解对象分片以及基类与派生类对象的转换
 *          以及派生类指针或引用与基类指针或引用之间
 *          的转换
 *
 *          c++的规则就是从下到上的转换是正常的
 *          派生类对象 -> 基类对象(好比派生类是一个学生
 *          ，基类是一个人，基类对象说我需要一个人，学生
 *          是人吗，是的，这就够了)
 *
 *          基类对象 -> 派生类对象(派生类对象是一个学生
 *          ，它需要一个学生来为我解答微积分等大学相关的
 *          问题，那么你拉过来一个人，他一定是大学生或者
 *          会微积分的学生吗，不是吧)
 *
 *          按照这样的逻辑去理解指针或引用也是一样的
 *          其实最主要的就是派生类对象中是包含这个基类的
 *          因此 它具备一个完整基类对象的数据，但是基类
 *          是不包含派生类对象的所有数据的，它是派生类的
 *          一部分，如果要基类转换为派生类那就是内存越界
 *          访问了
 * @author  bitofux
 * @date    2025-09-29
 ****************************************************/
#include <iostream>
using std::cout;
using std::endl;

#if 0  // 继承，派生类构造过程
class base {
public:
    int ma_;
    base() { cout << "base::base()\n"; }

protected:
    int mb_;

private:
    int mc_;
};

// public方式继承base
class derived : public base {
public:
    derived()
        : base() {  // 可在派生类构造函数中指定构造基类子对象的构造函数，否则就调用基类默认构造
        cout << "derived::derived()\n";
    }
    int md_;
    // 测试derived内部对public继承访问base不同访问修饰符的成员
    void test() {
        // base:public -> can
        cout << "base::ma_: " << ma_ << "\n";
        // base:protected -> can
        cout << "base::mb_: " << mb_ << "\n";
        // base:private -> can not 不可见
        // cout << "base::mc_: " << mc_ << "\n";
    }

protected:
    int me_;

private:
    int mf_;
};
#endif

// 重载、隐藏
class base {
public:
    int ma_;
    // 同一个作用域下的函数名相同，参数列表不同的一组函数
    // 构成函数重载关系
    void show() { cout << "base::show()\n"; }
    void show(int) { cout << "base::show(int)\n"; }
};
class derived : public base {
public:
    // 与基类的show不构成重载关系，作用域不同
    void show() { cout << "derived::show()\n"; }
};
int main() {
    derived d1;
    // 调用当前derived作用域下
    d1.show();
    // 当前作用域找到了show函数,不会再去base作用域下
    // 寻找,若derived没有show函数，则去寻找base作用域下
    // 若derived中有这个base类中同名的函数,则base中同名
    // 函数会被隐藏，除非你使用作用域解析运算符显示调用
    d1.base::show(10);
}
