// 拷贝构造函数的调用时机
// 1.当一个函数的形式参数是类、结构体类型
// 2.函数的返回值是一个类、结构体类型
// 3.使用已有对象去构造一个新对象
#include <cstring>
#include <iostream>

class Computer {
public:
  Computer(const char *name, const int age)
      : m_name{name ? new char[strlen(name) + 1]{} : nullptr}, m_age{age} {
    strcpy(m_name, name);
    using std::cout;
    cout << "Computer(const char*,const int)" << "\n";
  }
  // //拷贝构造函数(可读性有点差)
  // Computer(const Computer& other)
  // :m_name{other.m_name?static_cast<char*>(std::memcpy(new
  // char[strlen(other.m_name) + 1],other.m_name,strlen(other.m_name) +
  // 1)):nullptr} ,m_age(other.m_age){
  //   using std::cout;
  //    cout << "Computer(const Computer&)" << "\n";
  // }
  // 拷贝构造函数
  Computer(const Computer &other) {
    if (other.m_name) {
      auto len = std::strlen(other.m_name) + 1;
      m_name = new char[len]{};
      std::memcpy(m_name, other.m_name, len);
    } else {
      m_name = nullptr;
    }
    std::cout << "Computer(const Computer&)" << "\n";
  }
  void print() const {
    using std::cout;
    cout << "name: " << m_name << "\n" << "age: " << m_age << "\n";
  }
  ~Computer() {
    delete[] m_name;
    using std::cout;
    cout << "~Computer()" << "\n";
  }

private:
  char *m_name;
  int m_age;
};

// 1.函数的形式参数是Computer
void say(Computer c1) { c1.print(); }
void test() {
  Computer c1{"bitofux", 0};
  say(c1);
}

// 2.函数的返回值类型是Computer
Computer getObj() { return Computer{"wangshuai", 12}; }
int main() {
  // test();
  Computer c3 = getObj();
  return 0;
}
