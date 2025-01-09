#include <iostream>

int main () {

  signed char character1 {'a'};
  signed char character2 {'b'};
  signed char character3 {'c'};

  std::cout << "character1: " << character1 << std::endl;
  std::cout << "character2: " << character2 << std::endl;
  std::cout << "character3: " << character3 << std::endl;

  // one byte in memory: 2^8 different value (0 ~ 255)
  std::cout << std::endl;
  signed char value = 65;//ASCII character code for 'A'
  std::cout << "value(character): " << value << std::endl;
  std::cout << "value(sigend short): " << static_cast<signed short>(value) << std::endl;
  return 0;
}
