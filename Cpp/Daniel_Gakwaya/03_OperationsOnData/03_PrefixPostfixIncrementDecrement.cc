#include <iostream>

int main () {

  unsigned int value  = 5;

  //Increment by one
  value += 1;
  std::cout << "The value is : " << value << std::endl;

  value = 5;//Reset value to 5

  //Decrement by one
  value -= 1;
  std::cout << "The value is : " << value << std::endl;

  std::cout << "=====Postfix increment and decrement=====" << std::endl;
  //reset value to 5
  value = 5;

  std::cout << "The value is (increment) : " << value++ << std::endl;//right value
  std::cout << "The value is : " << value << std::endl;

  std::cout << std::endl;
  //Decrement with Postfix
  value = 5;//reset value to 5

  std::cout << "The value is (decrement) : " << value-- << std::endl;
  std::cout << "The value is : " << value << std::endl;

  std::cout << "=====prefix increment and decrement=====" << std::endl;
  value = 5;//Reset value to 5
  std::cout << "The value is (increment) : " << ++value << std::endl;//left value
  std::cout << "The value is : " << value << std::endl;
  value = 5;//Reset value to 5
  std::cout << "The value is : " << --value << std::endl;

  return 0;
}
