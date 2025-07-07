//编写一个程序，要求用户输入一个数字(1-7)，然后输出对应的星期几(Monday,Tuesday,...,Sunday)

#include <iostream>

int main () {
  //保存用户输入的数字
  unsigned short number = 0;

  //提示用户输入一个数字
  std::cout << "输入一个数字(1-7): \n";
  std::cin >> number;

  //输出对应的星期几
switch (number) {
  case 1: {      
    std::cout << "Monday\n";
    break;
    }
  case 2: {
    std::cout << "Tuesday\n";
    break;
    }
  case 3: {
    std::cout << "Wednesday\n";
    break;
    }
  case 4: {
    std::cout << "Thursday\n";
    break;
    }
  case 5: {
    std::cout << "Friday\n";
    break;
    }
  case 6: {
    std::cout << "Saturday\n";
    break;
    }
  case 7: {
    std::cout << "Sunday\n";
    break;
    }
  default:{
    std::cout << "error!\n";
    }
  }
  
  return 0;
}
