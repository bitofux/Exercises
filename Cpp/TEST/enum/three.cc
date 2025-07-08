#include <cstring>
#include <iostream>

union Data {
  int i;
  float f;
  char str[20];
};

int main() {
  Data data;

  //存储整数
  data.i = 42;
  std::cout << "Integer: " << data.i << std::endl;

  //存储浮点数 (注意: 会覆盖之前的整数数据)
  data.f = 3.14f;
  std::cout << "Float: " << data.f << std::endl;

  //存储字符串
  strcpy(data.str, "Hello, Union!");
  std::cout << "String: " << data.str << std::endl;

  //size of union Data
  std::cout << "size of union data: " << sizeof(union Data) << std::endl;

  return 0;
}
