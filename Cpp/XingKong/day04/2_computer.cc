// 类的声明和定义分开
#include <cstring>
#include <iostream>

using std::cout;
using std::endl;

//class的默认访问权限修饰符是private
class computer { //{}内部的称为类内,外部的都称为类外
public:
  void setBrand(const char *brand);
  void setPrice(const float price);
  void print();

private:
  char m_brand[20];
  float m_price;
};

// 类成员函数的实现
void computer::setBrand(const char *brand) { strcpy(this->m_brand, brand); }
void computer::setPrice(const float price) { this->m_price = price; }
void computer::print() {
  cout << "brand: " << this->m_brand << endl
       << "price: " << this->m_price << endl;
}

int main() {
  computer pc;
  pc.setBrand("apple");
  pc.setPrice(20.22);
  pc.print();
  return 0;
}
