#include <iostream>
#include <iomanip>

int main () {

  //Declare and initialize the variable
  //and print out the size
  float frac_number1 {1.12345678901234567890f}; //precision: 7
  std::cout << "sizeof(frac_number1): " << sizeof(frac_number1) << std::endl;
  double frac_number2 {1.12345678901234567890}; //precision: 15
  std::cout << "sizeof(frac_number2): " << sizeof(frac_number2) << std::endl;
  long double frac_number3 {1.12345678901234567890L};// precision >= 15
  std::cout << "sizeof(frac_number3): " << sizeof(frac_number3) << std::endl;

  std::cout << std::setprecision(20);
  std::cout << "frac_number1: " << frac_number1 << std::endl;
  std::cout << "frac_number2: " << frac_number2 << std::endl;
  std::cout << "frac_number3: " << frac_number3 << std::endl;
  
  //float problems: the precision is usually too limited
  //for a lot of applications
  float frac_number4 {192400023.0f};//7precision: 192400016 16 is garbage value
  double frac_number5 {192400023.0};//15precision: 192400023
  std::cout << "frac_number4: " << frac_number4 << std::endl;
  std::cout << "frac_number5: " << frac_number5 << std::endl;

  std::cout << "------------------------------" << std::endl;

  double frac_number6 {192400023};
  double frac_number7 {1.92400023e8};
  double frac_number8 {1.924e8};

  double frac_number9 {0.00000000003498};
  double frac_number10 {3.498e-11};// multiply with 10 exp(-11)
  std::cout << "frac_number6: " << frac_number6 << std::endl;
  std::cout << "frac_number7: " << frac_number7 << std::endl;
  std::cout << "frac_number8: " << frac_number8 << std::endl;

  std::cout << "frac_number9: " << frac_number9 << std::endl;
  std::cout << "frac_number10: " << frac_number10 << std::endl;

  //infinity and Nan
  std::cout << std::endl;
  std::cout << "infinity and Nan" << std::endl;

  float frac_number11 {5.6f};
  float frac_number12 {};//initialized to 0
  float frac_number13 {};//initialized to 0
  // +infinity
  float result {frac_number11 / frac_number12};
  std::cout << frac_number11 << "/" << frac_number12 << " yields " << result << std::endl;
  std::cout << result << " + " << frac_number11 << " yields " << result + frac_number11 << std::endl;
  // -infinity
  result  = (-frac_number11) / frac_number12;
  std::cout << frac_number11 << "/" << frac_number12 << " yields " << result << std::endl;
  std::cout << result << " + " << frac_number11 << " yields " << result + frac_number11 << std::endl;
  // Nan
  result = frac_number12 / frac_number13;
  std::cout << frac_number12 << "/" << frac_number13 << " = " << result << std::endl;
  return 0;
}
