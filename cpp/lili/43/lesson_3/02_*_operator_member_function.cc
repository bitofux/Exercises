// 运算符->重载 成员函数形式
#include <cstddef>
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
    ~SecondLayer() { std::cout << "~SecondLayer()\n"; 
        delete pdata_;
        pdata_ = nullptr;
    }

private:
    Data* pdata_;
};

class ThirdLayer {
public:
    ThirdLayer(SecondLayer* sl)
        :sl_{sl} {
        std::cout << "ThirdLayer(SecondLayer*)\n";
    }
    //重载*运算符 非const
    SecondLayer& operator*() {
        return *sl_;
    }
    const SecondLayer& operator*() const {
        return *sl_;
    }
    ~ThirdLayer() {
        std::cout << "~ThirdLayer()\n";
        delete sl_;
        sl_ = nullptr;
    }
private:
    SecondLayer* sl_;
};

void test() {
    ThirdLayer tl {new SecondLayer{new Data {30}}};
    //((tl.operator*()).operator->()).getData();
    //*tl返回的是SecondLayer的引用
    std::cout << (*tl)->getData() << '\n';
}

int main() {
    test();

    return 0;
}
