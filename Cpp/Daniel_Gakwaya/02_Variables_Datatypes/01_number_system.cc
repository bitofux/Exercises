#include <iostream>

int main () {

  int number1 = 15;//Decimal
  int number2 = 017;//Octal
  int number3 = 0x0F;//Hex
  int number4 = 0b1111;//C++14 Binary

  std::cout << "number1: " << number1 << std::endl;
  std::cout << "number2: " << number2 << std::endl;
  std::cout << "number3: " << number3 << std::endl;
  std::cout << "number4: " << number4 << std::endl;
}
