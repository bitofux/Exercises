/*定义一个class，它包含一个动态分配的整型数组作为成员。为这个类实现构造函数来初始化数组，并实现析构函数来释放数组。在main函数中创建该类的对象，并在对象生命周期结束后观察内存是否被正确释放。*/

#include <iostream>

class Human {
public:
    Human():ptr_{new int[5]{}}{}
    ~Human() {
        delete []ptr_;
    }
private:
    int* ptr_;
};
int main() {
    Human h1;

    return 0;
}
