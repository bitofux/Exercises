#include <cstdio>
#include <iostream>

enum Color {
  RED,
  GREEN,
  BLUE
};

int main() {
  Color favoriteColor = GREEN;

  if (favoriteColor == RED) {
      std::cout << "Your favorite color is red." << std::endl;
  } else if (favoriteColor == GREEN) {
      std::cout << "Your favorite color is green." << std::endl;
  } else if (favoriteColor == BLUE) {
      std::cout << "Your favorite color is blue." << std::endl;
  }

  //枚举类型的内存表示
  printf("size of enum Color: %zu\n",sizeof(enum Color));

  return 0;
}
