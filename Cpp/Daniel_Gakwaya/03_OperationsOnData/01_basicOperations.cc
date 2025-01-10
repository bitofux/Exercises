#include <iostream>

int main () {

  signed int number1{7};
  signed int number2{2};

  //Addition
  auto result {number1 + number2};
  std::cout << "result: " << result << std::endl;

  //subtraction
  result = number1 - number2;
  std::cout << "result: " << result << std::endl;

  //Multiplicatioon
  result = number2 * number1;
  std::cout << "result: " << result << std::endl;

  //Divison
  result = number1 / number2; //3
  std::cout << "result: " << result << std::endl;
  auto result_float = number1 / static_cast<float>(number2);// 3.5
  std::cout << "result_float: " << result_float << std::endl;

  //Modulus only integer.Not fraction number
  result = number1 % number2;
  std::cout << "result: " << result << std::endl;
  return 0;
}
