//析构函数函数主要用于释放资源

#include <cstring>
#include <iostream>

class Computer{
public:
  Computer(const char* name,const int age = -1)
  :m_name{name?new char[strlen(name) + 1]{}:nullptr}
  ,m_age{age}{
    strcpy(m_name, name);
    using std::cout;
    cout << "Computer(const char*,const int)" << "\n";
  }
  void print()const {
    using std::cout; 
    cout << "name: " << m_name << "\n" << "age: " << m_age << "\n";
  }
private:
  char* m_name;
  int m_age;
};

int main () {
  Computer c1{"xiaomi",20};
  c1.print();
  return 0;
}
