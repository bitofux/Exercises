//默认无参构造函数和有参构造函数
//初始化列表
#include <cstddef>
#include <cstring>
#include <iostream>

using std::cout;

class human{
public:
  //有参构造函数 编译器不会再为你添加一个无参数构造,如果还想无参构造，可以使用默认函数。
  human(const char* name = "null",const int age = -1);
  void print();
private:
  char m_name[20];
  int m_age;
};
//利用初始化列表初始化数据成员
human::human(const char* name,int age):m_age{age}{
  memset(this->m_name, 0, sizeof this->m_name);
  strcpy(this->m_name, name);
  cout << "human(const char*,int)" << "\n";
}
void human::print(){
  cout << "name: " << this->m_name << "\n"
       << "age: " << this->m_age << "\n";
}
int main (){
  // human h1;当类中出现一个带有参数的构造函数时，编译器不会再提供一个默认的无参构造函数，不可以在用一个无参去构造对象，除非自己添加一个
  human h1{"bitofux",20};
  h1.print();
  //使用默认值构造
  human h2;
  h2.print();
  return 0;
}
