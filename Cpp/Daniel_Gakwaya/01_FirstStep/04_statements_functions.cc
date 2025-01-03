#include <iostream>

int addNumbers(int first_param,int second_param){
  int result = first_param + second_param;
  return result;
}

int main () {

  int first_number {10};//statement
  int second_number {20};//statement

  std::cout << "first_number: " << first_number << std::endl;
  std::cout << "second_number: " << second_number << std::endl;

  int sum = first_number + second_number;
  std::cout << "sum: " << sum << std::endl;

  sum = addNumbers(1, 2);
  std::cout << "sum: " << sum << std::endl;

  sum = addNumbers(3, 4);
  std::cout << "sum: " << sum << std::endl;

  std::cout << "addNumbers(5,6): " << addNumbers(5, 6) << std::endl;

  return EXIT_SUCCESS;
}
