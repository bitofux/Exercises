#include <iostream>

int main () {

  int var1 {123};// Declare and initialize
  std::cout << "var1 : " << var1 << std::endl;

  var1 = 55;// Assign
  std::cout << "var1 : " << var1 << std::endl;

  std::cout << "------------------" << std::endl;

  double var2 {22.22};// Declare and initialize
  std::cout << "var2 : " << var2 << std::endl;
  var2 = 33.33;// Assign
  std::cout << "var2 : " << var2 << std::endl;

  std::cout << "------------------" << std::endl;
  
  bool state {true};
  std::cout << std::boolalpha;
  std::cout << "state : " << state << std::endl;
  state = false;//Assign
  std::cout << "state : " << state << std::endl;

  //auto type deduction
  auto var3 {333u};// Declare and initialize with type deduction
  var3 = -22;// var3 cant store signed integer.
  std::cout << "var3 : " << var3 << std::endl;// not -22
  return 0;
}
