#include <iostream>


void swap1(int x ,int y ){
  int tmp = x;
  x = y;
  y = tmp;
}
void swap(int* const p1,int* const p2){
  int tmp = *p1;
  *p1 = *p2;
  *p2 = tmp;
}

void swap(int &ref,int &ref1){
  int tmp = ref;
  ref = ref1;
  ref1 = tmp;
}
void test() {
  using std::cout;
  using std::endl;
  int a = 10,b = 20;
  cout << "a=" << a << " b=" << b << endl;
  swap1(a, b);
  cout << "a=" << a << " b=" << b << endl;
}
void test1() {
  using std::cout;
  using std::endl;
  int a = 10,b = 20;
  cout << "a=" << a << " b=" << b << endl;
  swap(&a, &b);
  cout << "a=" << a << " b=" << b << endl;
  
}
void test2() {
  using std::cout;
  using std::endl;
  int a = 10,b = 20;
  cout << "a=" << a << " b=" << b << endl;
  swap(a, b);
  cout << "a=" << a << " b=" << b << endl;
}

int main () {

  // test();
  // test1();
  test2();
  return 0;

}
