#include "namespace.h"
#include <iostream>

int main () {
  mylib::Counter c;
  c.increment();
  std::cout << mylib::library_name << " counter = " << c.value() << "\n";
  std::cout << "3 + 4 = " << mylib::add(3,4) << "\n";
}
