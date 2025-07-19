/*定义一个基类Shape，包含至少一个纯虚函数draw()。然后定义两个派生类Circle和Rectangle，分别实现draw()函数以绘制圆形和矩形。在main函数中，通过基类指针数组来存储不同形状的对象，并调用它们的draw()函数*/
#include <iostream>

#define PI 3.14
class Shape {
public:
    virtual void draw() = 0;
};

// 圆
class Circle : public Shape {
public:
    Circle(float radius)
        : radius_(radius) {}
    void draw() override {
        std::cout << "开始绘制圆...\n";
        std::cout << "周长: " << 2 * radius_ * PI << "\n";
    }

private:
    float radius_;
};
// 矩形
class Rectangle : public Shape {
public:
    Rectangle(float length, float width)
        : length_{length},
          width_(width) {}
    void draw() override {
        std::cout << "开始绘制矩形...\n";
        std::cout << "周长: " << 2 * (length_ + width_) << "\n";
    }

private:
    float length_;
    float width_;
};

int main() {
    // 基类指针数组
    Shape* arr[2];

    // 定义圆和矩形类的对象
    Rectangle r1{2.5, 10.2};
    Circle c1{5.2};

    // 保存两个对象的地址到arr
    arr[0] = &r1;
    arr[1] = &c1;

    // arr[0]调用draw函数
    arr[0]->draw();

    // arr[1]调用draw函数
    arr[1]->draw();

    return 0;
}
