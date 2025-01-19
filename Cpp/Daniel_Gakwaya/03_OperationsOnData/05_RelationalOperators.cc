#include <iostream>

int main() {

  unsigned int number1{23};
  unsigned int number2{56};

  std::cout << "number1 : " << number1 << std::endl;
  std::cout << "numebr2 : " << number2 << std::endl;

  std::cout << "Comparing variable" << std::endl;
  std::cout << std::endl;

  std::cout << std::boolalpha;
  std::cout << "number1 < number2: " << (number1 < number2) << std::endl;
  std::cout << "number1 <= number2: " << (number1 <= number2) << std::endl;
  std::cout << "number1 > number2: " << (number1 > number2) << std::endl;
  std::cout << "number1 >= number2: " << (number1 >= number2) << std::endl;
  std::cout << "number1 == number2: " << (number1 == number2) << std::endl;
  std::cout << "number1 != number2: " << (number1 != number2) << std::endl;

  std::cout << std::endl;
  std::cout << "store comparison result and use it later" << std::endl;

  bool result{number1 == number2};
  std::cout << "number1 == " << "number2: " << (number1 == number2)
            << std::endl;
}
