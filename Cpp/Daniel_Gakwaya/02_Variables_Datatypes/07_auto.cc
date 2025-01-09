#include <iostream>

int main () {
  
  auto var1 {12};//signed int
  auto var2 {12.1f};//float
  auto var3 {22.0};//double
  auto var4 {33.2l};//long double
  auto var5 {'e'};//signed char
  auto var6 {true};//bool

  auto var7 {123u};//unsigned int
  auto var8 {123ul};//unsigned long
  auto var9 {1234ull};//unsigned long long

  std::cout << "var1 occupies : " << sizeof(var1) << " bytes" << std::endl;
  std::cout << "var2 occupies : " << sizeof(var2) << " bytes" << std::endl;
  std::cout << "var3 occupies : " << sizeof(var3) << " bytes" << std::endl;
  std::cout << "var4 occupies : " << sizeof(var4) << " bytes" << std::endl;
  std::cout << "var5 occupies : " << sizeof(var5) << " bytes" << std::endl;
  std::cout << "var6 occupies : " << sizeof(var6) << " bytes" << std::endl;
  std::cout << "var7 occupies : " << sizeof(var7) << " bytes" << std::endl;
  std::cout << "var8 occupies : " << sizeof(var8) << " bytes" << std::endl;
  std::cout << "var9 occupies : " << sizeof(var9) << " bytes" << std::endl;

  std::cout << "type long: " << sizeof(long) << std::endl;
  std::cout << "type long long: " << sizeof(long long) << std::endl;
  return 0;
}
