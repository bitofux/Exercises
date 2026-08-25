/*
 * PROJECT : EXERCISES
 * FILE    : 2.primitive_types_variables.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-08-23
 * BRIEF   : 类型与变量
 * -- 算术类型、void 类型
 *  1. 整数类型
 *      整数类型：bool char wchar_t char16_t char32_t short int long
 *  2. 浮点数类型
 *      float 和 double
 *  3. void是一种特殊类型，用于特殊场合；例如与指针和函数搭配使用
 *
 * -- C++ 提供了可以改变类型含义的修饰符
 *  1. 这些修饰符包含了signed unsigned short
 * long；但是signed和unsigned只能用于整数类型，不可用于浮点数类型
 *
 * -- 所有类型都可以使用限定符来修饰
 *  1. const 限定符
 *  2. volatile
 *  3. static
 *
 * -- 所有类型都会占用内存，并且可以存储一定范围的值
 *  但是要注意在不同的平台下相同的类型可能有不同的内存表示：比如在16位平台下int类型是2个字节，但是在32位下是4个字节
 *
 * -- 类型大小
 *  bool、char 占用1个字节
 *  wchar_t、short在内存中占用两个字节
 *  int、long、float在内存中占用4个字节
 *  long long、double、long double 占用8个字节
 *  一个类型能存储的最小值和最大值，称为它的值域。无需死记硬背，在C++中提供了查询值域的方法，在<climit>头文件中有很多的宏
 *  查看浮点类型的取值范围，可以查看<cfloat>头文件
 *
 *  标识符(identifier) 初始化器(initializer)
 */

#include <iostream>

void uniform_initialization() {
    /* 标量类型 */

    // 定义一个整数类型的变量
    int i{10};
    std::cout << "i: " << i << std::endl;

    // 定义一个字符类型的变量
    char ch{'a'};
    std::cout << "ch: " << ch << std::endl;

    // 定义一个布尔类型的变量
    bool flag{true};

    // 定义一个float和double类型的变量
    float f{1.272f};
    double d{521.282};

    /* 向量类型 */
    int arr[5]{1, 2, 3, 4, 5};
    for (size_t i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i) {
        std::cout << "arr[" << i << "]: " << arr[i] << "\n";
    }
}

int main() {
    /* 标量类型：scalar type */

    // 定义一个整数类型的变量
    int i = 10;
    std::cout << "i: " << i << std::endl;

    // 定义一个字符类型的变量
    char ch = 'a';
    std::cout << "ch: " << ch << std::endl;

    // 定义一个布尔类型的变量
    bool flag = true;  // true or false

    // 定义一个float和double类型的变量
    float f = 1.272f;
    double d = 521.282;

    /* 向量类型：vector type */

    // 定义一个未初始化的数组类型
    int arr[5];

    // 定义一个初始化的数组
    int arr1[5] = {1, 2, 3, 4, 5};

    uniform_initialization();
}
