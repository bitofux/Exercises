#include <iostream>

int main () {

  bool red_right {true};
  bool green_light {false};

  if(red_right == true){
    std::cout << "Stop!" << std::endl;
  }else{
    std::cout << "Go through!" << std::endl;
  }

  if(green_light){
    std::cout << "the light is green!" << std::endl;
  }else{
    std::cout << "the light is NOT green!" << std::endl;
  }

  //sizeof
  std::cout << "sizeof(bool): " << sizeof(bool) << std::endl;

  //printig out a bool
  //1 -->> true
  //0 -->> false
  std::cout << std::endl;
  std::cout << "red_right: " << red_right << std::endl;
  std::cout << "green_light: " << green_light << std::endl;

  std::cout << std::boolalpha;
  std::cout << "red_right: " << red_right << std::endl;
  std::cout << "green_light: " << green_light << std::endl;

  return 0;
}
