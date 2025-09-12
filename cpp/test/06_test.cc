/****************************************************
 * @file    06_test.cc
 * @brief   CGOODS类
 * @author  bitofux
 * @date    2025-09-05
 ****************************************************/
#include <cstdlib>
#include <cstring>
#include <iostream>

const int NAME_LEN = 20;

class Date {
public:
    Date(int year, int month, int day) {
        _year = year;
        _month = month;
        _day = day;
    }

private:
    int _year;
    int _month;
    int _day;
};
class CGOODS {
public:  // 给外部提供公有的方法来访问类内的私有数据成员
    // 商品初始化的成员函数
    void init(const char* name, const double price, const int amount);
    // 打印商品信息
    void show() const;  // const成员函数
    CGOODS()
        : _date{2000, 10, 12} {
        ++_count;
    };
    CGOODS(const char* name, const double price, const int amount)
        : _price{price},
          _amount{amount},
          _date{2000, 10, 12}  // 指定构造函数
    {
        std::strcpy(_name, name);
    }

    // 通常想要通过类的实例化来访问类内的数据成员
    // 都会为这些数据成员提供setxxx或getxxx的方法
    // 类内实现的成员函数,自动处理成inline函数
    void setName(const char* name) { std::strcpy(_name, name); }
    void setPrice(const double price) { _price = price; }
    void setAmount(const int amount) { _amount = amount; }

    const char* getName() { return _name; }
    double getPrice() { return _price; }
    int getAmount() { return _amount; }
    // 访问_count数据成员
    static int getCount() { return _count; }

private:                   // 商品的数据成员一般都是私有
    char _name[NAME_LEN];  // 商品名称
    double _price;         // 商品价格
    int _amount;           // 商品数量
    Date _date;            // 商品出产日期
    // 静态数据成员 不属于任何对象
    // 对象的大小依赖于普通成员,不包括静态数据成员
    static int _count;  // 商品的总个数
};
// 类外定义 -- 全局变量的属性,标识符的作用域在类内
int CGOODS::_count = 0;

// 类外定义类内的成员函数不会被自动inline,只能显示指定
void CGOODS::init(const char* name, const double price, const int amount) {
    std::strcpy(_name, name);
    _price = price;
    _amount = amount;
}
void CGOODS::show() const {
    std::cout << "name: " << _name << "\n";
    std::cout << "price: " << _price << "\n";
    std::cout << "amount: " << _amount << "\n";
}

int main() {
    CGOODS good1;  // 类实例化了一个对象
    good1.init("豆腐", 20.2, 200);
    good1.show();

    good1.setPrice(30.2);
    good1.setAmount(100);
    good1.show();

    CGOODS good2;
    good2.init("空调", 10000.0, 20);
    good2.show();
    // 先通过对象访问
    std::cout << good2.getCount() << "\n";

    // 但是通过对象访问一个这个函数,仿佛获取的是这个对象
    // 的属性一样,因此可以将这个函数设置为静态,使用类名
    // 去访问
    std::cout << CGOODS::getCount() << "\n";
    const CGOODS good3;
    // 常对象不可调用非const成员函数
    // 因为this指针的缘故,good3.show(/*&good3*/)
    //&good3的类型是const CGOODS* 而show函数的参数是
    // CGOODS*类型,由const CGOODS* -> CGOODS*是不可以的
    good3.show();
    return 0;
}
