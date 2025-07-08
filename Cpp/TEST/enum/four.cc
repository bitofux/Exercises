#include <iostream>

union data {
  int i;
  char integer[4];
};

int main() {
  union data d1 = {.i = 0x12345678};

  for (size_t i = 0;i < 4;i++) {
    std::cout << "integer[" << i << "]: " << std::hex << static_cast<int>(d1.integer[i]) << std::endl;
  }

  return 0;
}
