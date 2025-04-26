#include <iostream>

int main () {
  using std::cout;
  using std::endl;
  using std::cin;

  char buff[512];
  cout << "what is your name?";
  // cin >> buff;//遇到空格结束
  // cout << "your name is " << buff << endl;
  cin.getline(buff,64,'\n');
  cout << "your name is: " << buff << endl;

  int age;
  cin >> age;
  cout << "age is: " << age << endl;
  return 0;
}
