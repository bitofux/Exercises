#include <cstdlib>
#include <iostream>
using namespace std;

int compare(const void* par1,const void* par2){
  auto val1 = *static_cast<const int*>(par1);
  auto val2 = *static_cast<const int*>(par2);

  if(val1 < val2)
    return -1;
  if(val1 > val2)
    return 1;
  return 0;
}

int main () {

  int values[]{13,4,2,30,3};
  
  for(auto v: values){
    cout << v << " ";
  }
  qsort(values, 5, sizeof(int), compare);
  cout << "after sort" << "\n";
  for(auto v: values){
    cout << v << " ";
  }
}
