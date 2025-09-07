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
    void show() const;
    CGOODS()
        : _date{2000, 10, 12} {};
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

    const char* getName() const { return _name; }
    double getPrice() const { return _price; }
    int getAmount() const { return _amount; }

private:                   // 商品的数据成员一般都是私有
    char _name[NAME_LEN];  // 商品名称
    double _price;         // 商品价格
    int _amount;           // 商品数量
    Date _date;            // 商品出产日期
};

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

    return 0;
}
