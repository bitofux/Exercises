#include <cstring>
#include <iostream>
using std::cout;
using std::endl;


class computer{
public:
  void setBrand(const char* brand){
    strcpy(this->brand_,brand);
  }
  void setPrice(const float price){
    this->price_ = price;
  }
  void print(){
    cout << "brand: " << this->brand_ << endl
         << "price: " << this->price_ << endl;
  }
private:
  char brand_[20];
  float price_;
};

void test0() {
  computer pc;
  pc.setBrand("apple");
  pc.setPrice(10000.11);
  pc.print();
}

int main () {
  test0();

  return 0;
}
