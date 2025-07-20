#include <iostream>
#pragma pack(push, 1)
class Base {
public:
    // 构造函数
    Base(int data)
        : data_{data} {
        ++instance_cnt_;
    }
    // 虚析构函数
    virtual ~Base() {}
    // 静态函数
    static int getInstanceCnt() { return instance_cnt_; }
    // 非静态函数
    int getData() { return data_; }
    // 虚函数
    virtual void print() {
        std::cout << "[Base] address: " << this << ", data: " << this->data_ << std::endl;
    }

private:
    int data_;                 // non-static data
    static int instance_cnt_;  // static data
};

int Base::instance_cnt_ = 0;
#pragma pack(pop)

int main() {
    Base a {100};
    Base b {200};

    std::cout << "Size: " << sizeof(Base) << ", instance_cnt: " << Base::getInstanceCnt() << " " << a.getInstanceCnt() << " " << b.getInstanceCnt() << std::endl;
    a.print();
    b.print();

    return 0;
}
