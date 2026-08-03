/*
 * PROJECT : EXERCISES
 * FILE    : test_sort.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-07-09
 * BRIEF   : 测试std::sort
 */
#include <iostream>
#include <algorithm>
#include <string_view>
#include <vector>

using std::cout;
using std::endl;
using std::sort;

template <class T>
using Type = std::vector<T>;

bool compare(int a, int b) { return a > b; }
int main() {
    Type<int> vec{1, 2, 34, 21, 44, 54, 65, 767, 213};

    auto print = [&vec](const std::string_view str) {
        for (auto& var : vec) {
            cout << var << " ";
        }
        cout << endl;
    };

    sort(vec.begin(), vec.end());

    print("sorted with the default operator<");

    struct {
        bool operator()(int a, int b) const { return a > b; }
    } custom;

    sort(vec.begin(), vec.end(), custom);
    print("sorted with the compare function");
}
