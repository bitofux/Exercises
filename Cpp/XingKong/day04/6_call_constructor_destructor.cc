/*
 * 1.析构函数：用于清理对象中的数据：释放堆内存，关闭打开的文件等等*/
/*析构函数函数的调用时机：
*1. 全局作用域下的对象构造是在main函数之前，析构发生在进程结束，main函数结束。
*2.块与函数作用域下的局部对象构造是发生在函数调用且执行到创建对象那条语句，析构是发生在当前函数结束
*3.块与函数作用域下的局部静态对象的构造也是发生在函数调用切执行到创建对象那条语句，但是仅此一次，因为它的析构是和全局作用域下的全局、静态对象是一样的。
*4.堆对象的构造发生在new时，析构发生在delete时
* */

#include <iostream>
using std::cout;
using std::string;

class human{
public:
  human(const string name = "null",const int age = -1):m_name{name},m_age{age}{
    cout << "human(const string,const int)" << "\n";
  }
  ~human(){
    cout << "~human()" << "\n";
  }
  void print() {
    cout << "name: " << m_name << "\n" << "age: " << m_age << "\n";
  }
  private:
  string m_name;
  int m_age;
};

//全局对象
// human h1;
//全局静态对象
// static human h1("wangshuai",27);

void test() {
  //函数内的局部静态对象
  static human h1{"bitofux",27};
}
int main (){
  cout << "entry main" << "\n";
  //代码块内的对象
  // {
  //   human h1{"bitofux",27};
  // }

  // test();

  //堆对象
  // human* ptr = new human{"wangshuai",27};
  // ptr->print();
  // delete ptr;
  cout << "exit main" << "\n";

  return 0;
}
