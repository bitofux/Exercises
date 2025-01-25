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

  return 0;
}
