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
      return "monday";
      break;
    case TUESDAY:
      return "tuesday";
      break;
    case WEDNESDAY:
      return "wednesday";
      break;
    case THURSDAY:
      return "thursday";
      break;
    case FRIDAY:
      return "friday";
      break;
    case SATURDAY:
      return "saturday";
      break;
    case SUNDAY:
      return "sunday";
      break;
  }
}

int main() {
  size_t weekday = -1;

  std::cout << "请您输入星期几对应的数字(1-7): \n";
  std::cin >> weekday;

  std::cout << typeName(static_cast<enum Week>(weekday)) << "\n";

  return 0;
}
