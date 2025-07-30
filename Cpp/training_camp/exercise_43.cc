/*虽然字符串在C++中通常通过std::string处理，但了解C风格字符串（字符数组）的处理也是有益的。编写一个程序，声明一个字符数组作为字符串，并使用循环结构遍历字符串，打印出每个字符及其ASCII码值。*/

#include <cstddef>
#include <iostream>

int main() {
    const char arr[] = "bitofux!";

    size_t len = sizeof(arr) / sizeof(arr[0]);

    for (size_t i = 0; i < len; i++) {
        std::cout << "char: " << arr[i] << ", ASCII: " << static_cast<int>(arr[i]) << '\n';
    }

    return 0;
}
