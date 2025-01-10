#include <iostream>

int main() {

  signed int a{1};
  signed int b{2};
  signed int c{3};
  signed int d{4};
  signed int e{5};
  signed int f{6};
  signed int g{7};

  auto result = a + b * c - d / e - f + g;
  std::cout << "result : " << result << std::endl;

  result = a / b * c + d - e + f;
  std::cout << "result : " << result << std::endl;

  result = (a + b) * c - d / e - f + g;
  std::cout << "result: " << result << std::endl;

  return 0;
}
