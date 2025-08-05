#include <iostream>

int main() {
    int* array{new int[100]};
    for (int i = 0; i < 100; i++) {
        array[i] = i + 1;
    }

    int* ptr = array;
    std::cout << "*ptr: " << *ptr << std::endl;

    delete[] array;
    int* ptr2 = ptr;
    std::cout << "*Ptr2: " << *ptr2 << std::endl;

    return 0;
}
