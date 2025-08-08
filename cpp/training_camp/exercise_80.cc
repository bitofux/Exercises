// 定义一个std::vector<int>对象，并使用列表初始化来初始化
// 容器，包含元素{1,2,3,4,5}。遍历并打印该容器的所有元素
#include <iostream>
#include <vector>
int main() {
    std::vector<int> vec{1, 2, 3, 4, 5};

    for (const auto& ref : vec) {
        std::cout << ref << ' ';
    }
    std::cout << '\n';

    return 0;
}
