#include <sys/types.h>
#include <cstddef>
#include <cstdint>
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
    virtual ~Base() { std::cout << "destructor: " << this << std::endl; }
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
    // 堆上定义两个Base对象
    Base* ptr_a = new Base{100};
    Base* ptr_b = new Base{200};

    // 将指针值转换为无符号整数值
    uint64_t ptr_list[2] = {uint64_t(ptr_a), uint64_t(ptr_b)};

    for (int idx = 0; idx < 2; idx++) {
        uint64_t ptr = ptr_list[idx];
        std::cout << "instance " << idx << " address " << (void*)ptr << std::endl;

        // 类中指向虚函数表的指针数据成员的地址
        uint64_t pointer2vptr = ptr;
        // 类中data数据成员的地址
        uint64_t pointer2data = ptr + 8;

        // 获取类中指向虚函数表的指针数据成员的值
        uint64_t vptr = *((uint64_t*)pointer2vptr);
        // 获取类中data数据成员的值
        int data = *((int32_t*)pointer2data);

        std::cout << "类中指向虚函数表的指针数据成员的地址: " << (void*)pointer2vptr
                  << ", 虚函数表的地址: " << (void*)vptr << std::endl;
        std::cout << "类中数据成员data的地址: " << (void*)pointer2data
                  << ", 类中数据成员data的值: " << data << std::endl;
        // 关于虚函数表
        // 1. 成员存放按照8字节对齐
        // 2. 成员依次顺序是: offset, type_info,
        // virtual_func1,virtual_func2...虚函数在虚表的顺序和声明的顺序一样
        // 3. 其中offset是一个整型,其余的都是地址值
        // 4. 类中的指向虚函数表的指针中保存的地址值不是虚函数表真正的入口地址,在其前还有两个条目
        // 5. GCC对于虚析构函数会生成两个虚函数

        // 由于虚函数表是8字节对齐，因此我将vptr类型转换为uint64_t*类型,方便做指针运算操作各个条目

        // 拿到虚函数表的真实起始地址
        uint64_t* vtable = ((uint64_t*)vptr) - 2;

        // 第一个条目的地址和存储的值:offset
        uint64_t* offset_ptr = vtable;
        uint64_t offset = *(vtable);

        // 第二个条目的地址和存储的值:RTTI
        // 这是一个地址值,我使用无符号整型保存:8个字节
        uint64_t* rtti_ptr = vtable + 1;
        uint64_t rtti = *(vtable + 1);

        // 第三个条目的地址和存储的值: 析构函数函数生成的第一个虚函数
        uint64_t* destructor1_ptr = vtable + 2;
        uint64_t destructor1 = *(vtable + 2);

        // 第四个条目的地址和存储的值: 析构函数生成的第二个虚函数
        uint64_t* destructor2_ptr = vtable + 3;
        uint64_t destructor2 = *(vtable + 3);

        // 第五个条目的地址和存储的值: print虚函数
        uint64_t* print_fn_ptr = vtable + 4;
        uint64_t print_fn = *(vtable + 4);

        std::cout << "vtable address: " << vtable << std::endl;
        std::cout << "offset address: " << offset_ptr << ", offset value: " << (ptrdiff_t)offset
                  << std::endl;
        std::cout << "type_info address: " << rtti_ptr << ", rtti value: " << (void*)rtti
                  << std::endl;
        std::cout << "destructor1 address: " << destructor1_ptr
                  << ", destructor1 value: " << (void*)destructor1 << std::endl;
        std::cout << "destructor2 address: " << destructor2_ptr
                  << ", destructor2 value: " << (void*)destructor2 << std::endl;
        std::cout << "print_fn address: " << print_fn_ptr << ", print_fn value: " << (void*)print_fn
                  << std::endl;
        std::cout << "\n";
    }

    return 0;
}
