#include <iostream>
#include <ios>
#include <iomanip>
#include <limits>
#include <cmath>

int main () {

  //Literal types : u and l combinations for unsigned and long
  unsigned char unsigned_char {53u};

  // 2bytes
  short short_var {-32768}; // no special literal type for short
  short int short_int {455}; // no special literal type for short
  signed short signed_short {122}; // no special literal type for short
  signed short int signed_short_int {-456}; // no special literal type for short
  unsigned short int unsigned_short_int {5678U};

  // 4 bytes
  const int int_var {55};
  signed int signed_int_var {66};
  signed signed_var {77};
  unsigned int unsigned_int {555u};

  // 4 or 8 bytes
  long long_var {88l};
  long int long_int {33l};
  signed long signed_long {44l};
  signed long int signed_long_int {44l};
  unsigned long int unsigned_long_int {555ul};

  long long long_long_var {888ll};
  long long int long_long_int_var {888ll};
  signed long long signed_long_long_var {444ll};
  signed long long int signed_long_long_int_var {555ll};
  unsigned long long int unsigned_long_long_int_var {555ull};

  //Grouping numbers: C++14 and onwards
  unsigned int prize {1'500'00'0u};
  std::cout << "The prize is : " << prize << std::endl;

  std::cout << "signed_long_long_int : " << signed_long_long_int_var << std::endl;

  return 0;
}
