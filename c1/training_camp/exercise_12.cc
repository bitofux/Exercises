//定义一个enum类型表示一周的七天. 编写一个程序,允许用户输入一个数字(1-7),然后输出对应的星期几名称
#include <iostream>

enum Week {
  MONDAY = 1,
  TUESDAY,
  WEDNESDAY,
  THURSDAY,
  FRIDAY,
  SATURDAY,
  SUNDAY
};

const char* typeName(enum Week week) {
  switch (week) {
    case MONDAY:
      return "Monday";
    case TUESDAY:
      return "Tuesday";
    case WEDNESDAY:
      return "Wednesday";
    case THURSDAY:
      return "Thursday";
    case FRIDAY:
      return "Friday";
    case SATURDAY:
      return "Saturday";
    case SUNDAY:
      return "Sunday";
    default:
      return "Non";
  }
}

int main() {
  int weekday = -1;

  while (true) {
    std::cout << "请您输入星期几对应的数字(1-7): \n";
    std::cin >> weekday;
    if (weekday < 0 || weekday > 7) {
      std::cout << "输入正确的数字!\n";
      continue;
    }
    break;
  }
  std::cout << typeName(static_cast<enum Week>(weekday)) << "\n";

  return 0;
}
