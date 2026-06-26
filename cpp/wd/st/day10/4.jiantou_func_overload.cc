/*
 * PROJECT : DAY10
 * FILE    : 4.jiantou_func_overload.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-06-26
 * BRIEF   : ->运算符重载的规则：递归解引用
 *           1.
 * 若一个类调用->运算符重载函数返回的是一个裸指针，则会强制添加一个->运算符访问这个指针指向的成员
 *           2.
 * 若返回的是一个已经重载了->运算符的类，那么会继续调用这个类的->运算符重载函数，直到遇到裸指针为止
 */

#include <iostream>

#if 0  // 返回的是一个裸指针 Data*
class Data {
public:
    Data(int data)
        : data_{data} {}
    int getData() { return data_; }

private:
    int data_;
};

class Middle {
public:
    Middle(Data* data)
        : data_{data} {}
    Data* operator->() { return data_; }

private:
    Data* data_;
};

void test() {
    Middle m1{new Data{10}};

    std::cout << m1->getData() << std::endl;
}

int main() {
    test();

    return 0;
}
#endif

#if 1  // 返回的是一个重载了->运算符的类对象 Data
struct human {
    human(int data = 100)
        : data_{data} {}
    int data_;
    void print() { std::cout << "human::data: " << data_ << std::endl; }
};

class Data {
public:
    Data(int data)
        : data_{new human{data}} {}

    // 重载->运算符
    human* operator->() {
        std::cout << "Data::operator->" << std::endl;
        return data_;
    }

    // 拷贝构造函数
    Data(const Data& rhs)
        : data_{new human{rhs.data_->data_}} {}
    ~Data() {
        delete data_;
        data_ = nullptr;
    }

private:
    human* data_;
};

class Middle {
public:
    Middle(Data data)
        : data_{data} {}
    Data operator->() {
        std::cout << "Middle::operator->" << std::endl;
        return data_;
    }

private:
    Data data_;
};

void test() {
    Middle m1{Data{20}};
    /*
     * ((m1.operator->()).operator->())->print();
     *
     * Middle::operator-> Data::operator-> print()
     */
    m1->print();
}

int main() {
    test();

    return 0;
}
#endif
