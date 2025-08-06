/*定义一个包含嵌套命名空间的复杂结构
 * 比如Geometry::Shapes在Shapes命名空间中定义
 * 两个函数calculateArea和calculatePerimeter
 * （假设为圆形，需要半径作为参数）
 * 在main函数中，使用using指令引入Geometry::Shapes命名空间
 * 中的所有元素,并调用这两个函数
 * */

#include <iostream>

#define PI 3.14
namespace Geometry {
namespace Shapes {
double calculateArea(const int radius) {
  return PI * radius * radius;
}
double calculatePerimeter(const int radius) {
  return 2 * PI * radius;
}
} //namespace Shapes; 
} //namespace Geometry;

int main() {
  using namespace Geometry::Shapes;
  std::cout << "半径为2的圆的周长: " << calculatePerimeter(2) << "\n";
  std::cout << "半径为2的圆的面积: " << calculateArea(2) << "\n";

  return 0;
}
