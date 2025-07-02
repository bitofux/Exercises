#include <cstring>
#include <iostream>
using std::cout;
using std::endl;

//struct默认访问权限是public,class的是private，其他的都一样
struct computer{
public:
  void setBrand(const char* brand);
  void setPrice(const float price);
  void print();
private:
  char m_brand[20];
  float m_price;
};

void computer::setBrand(const char* brand){
  strcpy(this->m_brand, brand);
}
void computer::setPrice(const float price){
  this->m_price = price;
}
void computer::print(){
  cout << "brand: " << this->m_brand << "\n"
  << "price: " << this->m_price << endl;
}
int main () {
  computer pc;
  pc.setBrand("bitofux");
  pc.setPrice(20.22);
  pc.print();
  return 0;
}
