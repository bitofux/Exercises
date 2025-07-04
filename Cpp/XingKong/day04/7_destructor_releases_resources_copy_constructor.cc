//析构函数函数主要用于释放资源
//拷贝构造函数的深拷贝
#include <cstring>
#include <iostream>

class Computer{
public:
  Computer(const char* name,const int age)
  :m_name{name?new char[strlen(name) + 1]{}:nullptr}
  ,m_age{age}{
    strcpy(m_name, name);
    using std::cout;
    cout << "Computer(const char*,const int)" << "\n";
  }
  // //拷贝构造函数(可读性有点差)
  // Computer(const Computer& other)
  // :m_name{other.m_name?static_cast<char*>(std::memcpy(new char[strlen(other.m_name) + 1],other.m_name,strlen(other.m_name) + 1)):nullptr}
  // ,m_age(other.m_age){
  //   using std::cout;
  //    cout << "Computer(const Computer&)" << "\n";
  // }
  // 拷贝构造函数
  Computer(const Computer& other){
    if(other.m_name){
      auto len = std::strlen(other.m_name) + 1;
      m_name = new char[len]{};
      std::memcpy(m_name,other.m_name,len);
    }else {
      m_name = nullptr;
    }
    std::cout << "Computer(const Computer&)" << "\n";
  }
  void print()const {
    using std::cout; 
    cout << "name: " << m_name << "\n" << "age: " << m_age << "\n";
  }
  ~Computer() {
    delete[] m_name;
    using std::cout;
    cout << "~Computer()" << "\n";
  }
private:
  char* m_name;
  int m_age;
};

int main () {
  Computer c1{"xiaomi",20};
  c1.print();
  Computer c2{c1};
  c2.print();
  return 0;
}
