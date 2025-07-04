//成员初始化顺序
//初始化列表只会按照数据成员在类内的顺序定义并初始化

//最佳实践：按照类内的数据成员顺序在初始化列表中去初始化
#include <iostream>
using std::cout;

class Point{
public:
  Point(const int ix,const int iy)
  :m_ix{ix}
  ,m_iy{iy}
  {
    cout << "const int,const int" << "\n";
  }
  void print(){
    cout << "(" << m_ix << "," << m_iy << ")" << "\n";
  }
private:
  int m_ix;
  int m_iy;
};

int main (){
  Point p1(10,20);
  p1.print();

  return 0;
}
