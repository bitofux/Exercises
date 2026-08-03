/*
 * PROJECT : EXERCISES
 * FILE    : overload_out_array.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-07-26
 * BRIEF   : 对内置数组类型重载输出流运算符>>
 */
#include <cstddef>
#include <iostream>
#include <ostream>
#include <wchar.h>

template <typename T, size_t N>
std::ostream& operator<<(std::ostream& os, const T (&arr)[N]) {
    os << reinterpret_cast<const char*>("[");

    for (int i = 0; i < N - 1; ++i) {
        os << arr[i] << reinterpret_cast<const char*>(",");
    }

    os << arr[N - 1] << reinterpret_cast<const char*>("]");

    return os;
}

template <typename T, size_t N>
std::wostream& operator<<(std::wostream& os, const T (&arr)[N]) {
    os << reinterpret_cast<const wchar_t*>(L"[");

    for (int i = 0; i < N - 1; ++i) {
        os << arr[i] << reinterpret_cast<const wchar_t*>(L",");
    }

    os << arr[N - 1] << reinterpret_cast<const wchar_t*>(L"]");

    return os;
}
int main() {
    int arr[] = {1, 2, 343, 4, 56, 76, 82};

    std::cout << arr << std::endl;

    return 0;
}
