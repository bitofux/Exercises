#include <iostream>
#include <ios>
#include <iomanip>
#include <cmath>
#include <limits>

int main () {

  const int age {34};
  const float height {1.67f};

  // age = 55; // cant modify
  // height = 1.8f;

  int years {3 * age};

  std::cout << "age : " << age << std::endl;
  std::cout << "height : " << height << std::endl;
  std::cout << "years : " << years << std::endl;

  return 0;
}
