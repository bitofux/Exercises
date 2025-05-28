#include <iostream>
using namespace std;

namespace ns{
  int ns_value = 0;
}
// int ns_value = 40;
// using namespace ns;//从这行语句开始,ns中的全部实体在当前作用域内可见
int main () {

  // int ns_value = 30;
  using namespace ns;//从这行语句开始,ns中的全部实体在当前作用域内可见
  ns_value = 20;
  cout << "ns::ns_value = " << ns::ns_value << endl;

  return 0;
}
