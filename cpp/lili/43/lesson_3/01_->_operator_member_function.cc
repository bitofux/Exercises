// 运算符->重载 成员函数形式
#include <iostream>

class Data {
public:
    Data(int data)
        : data_{data} {
        std::cout << "Data(int)\n";
    }
    int getData() const { return data_; }
    ~Data() { std::cout << "~Data()\n"; }

private:
    int data_;
};

class SecondLayer {
public:
    SecondLayer(Data* pdata)
        : pdata_{pdata} {
        std::cout << "SecondLayer(Data*)\n";
    }
    // 重载->运算符 非const
    Data* operator->() { return pdata_; }
    // 重载->运算符 const
    const Data* operator->() const { return pdata_; }
    ~SecondLayer() { std::cout << "~SecondLayer()\n"; }

private:
    Data* pdata_;
};

// 测试SecondLayer
void test() {
    SecondLayer s1{new Data{20}};

    // 重载->运算符 使用类的实例配合->
    // s1.operator->()返回Data*,而Data*就是一个指针
    // 可直接使用->运算符
    //(s1.operator->())->getData();
    std::cout << s1->getData() << '\n';
    std::cout << (s1.operator->())->getData() << '\n';
}

int main() {
    test();

    return 0;
}
