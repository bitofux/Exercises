#include <iostream>
#include "1_add_print.h"
using namespace std;

int main () {

  int x = 0,y = 0;
  cout << "输入两个整数: ";
  cin >> x >> y;
  int result = add(x,y);
  cout << "result: " << result << endl;

  cout << "输入一个字符: ";
  char ch = ' ';
  cin >> ch;
  print(ch);

  return 0;
}
