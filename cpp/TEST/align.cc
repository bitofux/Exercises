#include <iostream>
#include <cstddef>

using namespace std;

struct /*alignas(64)*/ Node {
  int id;
  double value;
};

int main () {
  cout << "alignas(Node) = " << alignof(Node) << '\n';
  cout << "sizeof(Node) = " << sizeof(Node) << "\n";
  return 0;
}
