#include <iostream>
#include <ios>
#include <iomanip>
#include <limits>

int main () {

  //short int 
  std::cout << "The range for short int is from " << std::numeric_limits<short int>::min() << " to " << std::numeric_limits<short int>::max() << std::endl;
  //unsigned short int
  std::cout << "The range for unsigned short int is from " << std::numeric_limits<unsigned short int>::min() << " to " << std::numeric_limits<unsigned short int>::max() << std::endl;

  //signed int
  std::cout << "The range for signed int is from " << std::numeric_limits<signed int>::min() << " to " << std::numeric_limits<signed int>::max() << std::endl;
  // unsigned int 
  std::cout << "The range for unsigned int is from " << std::numeric_limits<unsigned int>::min() << " to " << std::numeric_limits<unsigned int>::max() << std::endl;

  //signed long 
  std::cout << "The range for signed long is from " << std::numeric_limits<signed long>::min() << " to " << std::numeric_limits<signed long>::max() << std::endl;
  //unsigned long 
  std::cout << "The range for unsigned long is from " << std::numeric_limits<unsigned long>::min() << " to " << std::numeric_limits<unsigned long>::max() << std::endl;

  //float
  std::cout << "The range for float is from " << std::numeric_limits<float>::min() << " to " << std::numeric_limits<float>::max() << std::endl;
  //double 
  std::cout << "The range for double is from " << std::numeric_limits<double>::min() << " to " << std::numeric_limits<double>::max() << std::endl;
  //long double 
  std::cout << "The range for long double is from " << std::numeric_limits<long double>::min() << " to " << std::numeric_limits<long double>::max() << std::endl;

  //lowest
  std::cout << "The range(with lowest) for float is from " << std::numeric_limits<float>::lowest() << " to " << std::numeric_limits<float>::max() << std::endl;
  std::cout << "The range(with lowest) for double is from " << std::numeric_limits<double>::lowest() << " to " << std::numeric_limits<double>::max() << std::endl;
  std::cout << "The range(with lowest) for long double is from " << std::numeric_limits<long double>::lowest() << " to " << std::numeric_limits<long double>::max() << std::endl;

  std::cout << "int is signed : " << std::numeric_limits<unsigned int>::is_signed << std::endl;
  std::cout << "unsigned int digit : " << std::numeric_limits<unsigned int>::digits << std::endl;
  return 0;
}
