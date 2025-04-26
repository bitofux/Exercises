// 这是一个单行注释

/*
这是一个多行注释
*/

#include <iostream>
#include <type_traits>
using std::cout;
using std::endl;

enum e1 {};
enum class e2 {};

int main() {
  bool e1_type =
      std::is_same<int, typename std::underlying_type<e1>::type>::value;
  bool e2_type =
      std::is_same<int, typename std::underlying_type<e2>::type>::value;

  cout << "underlying type for 'e1' is " << (e1_type ? "int" : "non-int")
       << '\n';
  cout << "underlying type for 'e2' is " << (e2_type ? "int" : "non-int")
       << '\n';

  return 0;
}
