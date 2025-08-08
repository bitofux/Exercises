// 定义一个类Box，包含两个构造函数:一个接收两个int参数
//(表示宽度和高度)，另一个接收一个initializer_list<int>
// 参数(表示多个尺寸)
#include <iostream>
#include <initializer_list>
class Box {
public:
    Box(const int length, const int width)
        : length_{length},
          width_{width} {
        std::cout << "Box(const int ,const int)\n";
    }
    Box(std::initializer_list<int> data) {
        auto it{data.begin()};
        length_ = it[0];
        width_ = it[1];
        height_ = it[2];
        std::cout << "Box(std::initializer_list)<int>\n";
    }

private:
    int length_;
    int width_;
    int height_;
};
int main() {
    // 两个参数 使用()初始化
    Box b1(10, 20);

    // std::initializer_list 使用{}初始化
    Box b2{11, 21, 31};

    return 0;
}
