/*
 * PROJECT : EXERCISES
 * FILE    : 6.new_for_2darray.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-09-11
 * BRIEF   : 使用new创建二维数组
 */
#include <iostream>

void twoArray() {
    int* p1 = new int[3]{1, 2, 3};
    int* p2 = new int[3]{4, 5, 6};

    int** pData = new int*[2]{p1, p2};

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << pData[i][j] << " ";
        }
        std::cout << "\n";
    }

    delete[] pData;
    delete[] p1;
    delete[] p2;
}
void twoArray(int) {
    int (*ptr)[3] = new int[2][3]{{10, 20, 30}, {40, 50, 60}};
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << ptr[i][j] << " ";
        }
        std::cout << "\n";
    }
}
int main() {
#if 0
    int arr[2][3] = {{1,2,3},{4,5,6}};

    for (auto& var: arr) {
        for (auto &ele : var) {
            std::cout << ele << " ";
        }
        std::cout << "\n";
    }
#endif
    // twoArray();
    twoArray(10);
}
