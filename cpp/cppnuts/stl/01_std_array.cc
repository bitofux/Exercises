/****************************************************
 * @file    01_std_array.cc
 * @brief   syntax: std::array<T,N> array;
 *          N is compile time
 *
 *          std::array是一个固定大小的数组容器,N不可改变
 *          std::array<T,N>作为函数的一个参数时,传参是按
 *          值传递,不会退化为指针,其实就是一个类.当然你
 *          也可以按引用或者指针传递.
 *          常见的成员方法和支持的运算符
 *              at(): 会进行边界检查,越界会抛出异常
 *              []: 不会进行边界检查
 *              size(): 获取数组有效元素的个数
 *                      类型是std::array::size_type
 *              front(): 获取第一个元素
 *              back(): 获取最后一个元素
 *              data(): 获取内部数组的指针,指向第一个元素
 *              的指针
 * @author  bitofux
 * @date    2025-09-19
 ****************************************************/
#include <iostream>
#include <array>

int main() {
    // 声明
    // 注意以下两个数组的类型并不相同
    std::array<int, 2> arr_one;
    std::array<int, 3> arr_two;

    // 可以先定义,随后可以通过初始化列表对数组进行初始化
    // C中是不可以的
    arr_one = {1, 2};
    arr_two = {4, 5, 6};

    // 定义并初始化
    std::array<double, 2> arr_three = {2.2, 3.3};
    std::array<bool, 2> arr_four{true, false};  // 统一初始化
    // 通过at访问元素
    std::cout << "arr_two.at(1): " << arr_two.at(1) << "\n";
    // 通过[]运算符访问和修改
    arr_two[1] = 10;
    std::cout << "arr_two[1]: " << arr_two[1] << "\n";

    // 访问arr_two的第一个和最后一个元素
    std::cout << "arr_two.front(): " << arr_two.front() << "\narr_two.back(): " << arr_two.back()
              << "\n";

    // 获取内部数组的首元素的地址
    int* ptr_arr_two = arr_two.data();
    for (std::array<int, 3>::size_type i = 0; i < arr_two.size(); ++i) {
        std::cout << *(ptr_arr_two + i) << "\n";
    }

    return 0;
}
