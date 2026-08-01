/****************************************************
 * @file    5_7_new_delete.cc
 * @brief   剖析new和delete
 *          注意C++标准中，可重写的operator new和operator
 *          delete运算符重载函数在一些编译器自带的库中是
 *          弱符号，这允许用户自定义这些函数,且是强符号
 *          链接器对于强弱符号，只选择强符号,都是弱符号
 *          会进行合并
 *
 *          new和malloc的一些区别：
 *              1. malloc是按字节开辟的，而new开辟内存
 *                 需要指定的类型,所以malloc返回的是void*
 *                 new返回的是指向指定类型的指针
 *              2. malloc只负责开辟空间，而new还可以进行
 *                 初始化
 *              3. malloc失败返回void*,new失败会抛
 *                 bad_alloc异常
 *
 *          new -> delete
 *          new[] -> delete[]
 *
 *          想看看new -> delete[]
 *          new[] -> delete会有什么异常 这是未定义行为
 *          无论怎么不正确的配对new和delete
 *          最终都是要free，不正确的匹配会传入无效的指针
 *          导致程序异常终止
 *          大多数实现(比如glibc的ptmalloc)会在用户区前面
 *          加一个块头，里面有size、标志等信息。free会根据传入的指针回退到块头，从中取出大小并做一致性检查，比如对齐、边界、相邻块关系。如果传入的不是malloc返回的块首，回退后的数据就不正确，检查就会失败，glibc就会报free():invalid
 * pointer或munmap_chunk():invalid pointer
 * @author  bitofux
 * @date    2025-09-20
 ****************************************************/
#include <cstddef>
#include <iostream>
#include <cstdlib>
#include <new>

// 自定义operator new/new[]

void* operator new(std::size_t size) {
    void* ptr = malloc(size);
    if (!ptr) {
        throw std::bad_alloc{};
    }
    std::cout << "new: " << ptr << "\n";
    return ptr;
}
void* operator new[](std::size_t size) {
    void* ptr = malloc(size);
    if (!ptr) {
        throw std::bad_alloc{};
    }
    std::cout << "new[]: " << ptr << "\n";
    return ptr;
}

// 自定义operator delete/delete[]
void operator delete(void* p) {
    std::cout << "delete: " << p << "\n";
    free(p);
}
void operator delete[](void* p) {
    std::cout << "delete[]: " << p << "\n";
    free(p);
}

class test {
public:
    test() { std::cout << this << ": test()\n"; }
    ~test() { std::cout << this << ": ~test()\n"; }

private:
    int data_;
};
void test_normal_new_delete() {
    // 标准做法: 单个对象
    /*
     * 1. 分配内存
     * 2. 在指定内存处调用构造函数构造对象*/
    test* ptr_test = new test;
    std::cout << "ptr_test: " << (void*)ptr_test << "\n";
    std::cout << "8个字节: " << (int)*((char*)ptr_test - 8) << "\n";

    /*
     * 1.在ptr_test保存的地址处析构对象
     * 2.在ptr_test保存的地址处释放内存*/
    delete ptr_test;

    std::cout << "---------------------------\n";
    // 标准做法: 多个对象 对象数组
    test* ptr_test_arr = new test[2];
    std::cout << "ptr_test_arr: " << (void*)ptr_test_arr << "\n";

    delete ptr_test_arr;
}
void test_ub_new_delete_one() {}
int main() {
    test_normal_new_delete();
    return 0;
}
