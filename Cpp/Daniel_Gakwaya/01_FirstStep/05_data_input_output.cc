#include <iostream>
#include <string>

int main () {
  /*
  //printing data
  std::cout << "Hello World!" << std::endl;

  int age{21};
  std::cout << "age: " << age << std::endl;

  std::cerr << "Error message: something is wrong!" << std::endl;
  std::clog << "Log message: something happened!" << std::endl;*/

  /*
  //reading data from console
  int age1;
  std::string name;

  std::cout << "type in your name: ";
  std::cin >> name;
  std::cout << "type in your age: " ;
  std::cin >> age1;

  std::cout << "Hello " << name << ",Your age is " << age1 << " years old!" << std::endl;*/
  
  //reading data with space from console
  int age2;
  std::string name1;
  std::cout << "type in your name and age: ";
  
  std::getline(std::cin,name1);
  std::cin >> age2;

  std::cout << "Hello " << name1 << ",Your age is " << age2 << " years old!" << std::endl;
  
  return 0;
}
