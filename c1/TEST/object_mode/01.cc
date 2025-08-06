#include <iostream>

class WithAlign {
    int a;
    char b;
};

#pragma pack(push, 1)
class WithoutAlign {
    int a;
    char b;
};
#pragma pack(pop)

int main() {
    std::cout << "WithAlign: " << sizeof(WithAlign) << std::endl;
    std::cout << "WithoutAlign: " << sizeof(WithoutAlign) << std::endl;

    return 0;
}
