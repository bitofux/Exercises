#include <iostream>

int main() {
    int* ptr = new int[2]{};

    std::cout << ptr[0] << ptr[1];

    return 0;
}
