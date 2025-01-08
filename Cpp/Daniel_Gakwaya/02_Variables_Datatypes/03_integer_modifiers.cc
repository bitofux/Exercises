#include <iostream>

int main() {

  signed int value1{10};
  signed int value2{-10};

  std::cout << "value1: " << value1 << std::endl;
  std::cout << "value2: " << value2 << std::endl;
  std::cout << "sizeof(value1): " << sizeof(value1) << std::endl;
  std::cout << "sizeof(value2): " << sizeof(value2) << std::endl;

  unsigned int value3{20};
  // unsigned int value4 {-20};//Compier errors
  std::cout << "value3: " << value3 << std::endl;
  std::cout << "sizeof(value3): " << sizeof(value3) << std::endl;

  // short
  short short_var{24};
  short int short_int_var{-24};
  signed short signed_short_var{21};
  signed short int signed_short_int_var{-21};

  unsigned short int unsigned_short_var{21};
  std::cout << "short_var: " << short_var
            << " sizeof(short_var): " << sizeof(short_var) << std::endl;
  std::cout << "short_int_var: " << short_int_var
            << " sizeof(short_int_var): " << sizeof(short_int_var) << std::endl;
  std::cout << "signed_short_var: " << signed_short_var
            << " sizeof(signed_short_var): " << sizeof(signed_short_var)
            << std::endl;
  std::cout << "signed_short_int_var: " << signed_short_int_var
            << " sizeof(signed_short_int_var): " << sizeof(signed_short_int_var)
            << std::endl;
  std::cout << "unsigned_short_var: " << unsigned_short_var
            << " sizeof(unsigned_short_var): " << sizeof(unsigned_short_var)
            << std::endl;

  // long
  long long_var{30};
  std::cout << "long_var: " << long_var
            << " sizeof(long_var): " << sizeof(long_var) << std::endl;
  long int long_int_var{-31};
  std::cout << "long_int_var: " << long_int_var
            << " sizeof(long_int_var): " << sizeof(long_int_var) << std::endl;
  signed long signed_long_var{32};
  std::cout << "signed_long_var: " << signed_long_var
            << " sizeof(signed_long_var): " << sizeof(signed_long_var)
            << std::endl;
  signed long int signed_long_int_var{-32};
  std::cout << "signed_long_int_var: " << signed_long_int_var
            << " sizeof(signed_long_int_var): " << sizeof(signed_long_int_var)
            << std::endl;
  unsigned long int unsigned_long_int{0};
  std::cout << "unsigned_long_int: " << unsigned_long_int
            << " sizeof(unsigned_long_int): " << sizeof(unsigned_long_int)
            << std::endl;
  // long long
  long long ll_var{12};
  std::cout << "ll_var: " << ll_var << " sizeof(ll_var): " << sizeof(ll_var)
            << std::endl;
  long long int ll_int_var{-12};
  std::cout << "ll_int_var: " << ll_int_var
            << " sizeof(ll_int_var): " << sizeof(ll_int_var) << std::endl;
  signed long long signed_ll_var{23};
  std::cout << "signed_ll_var: " << signed_ll_var
            << " sizeof(signed_ll_var): " << sizeof(signed_ll_var) << std::endl;
  signed long long int signed_ll_int_var{-23};
  std::cout << "signed_ll_int_var: " << signed_ll_int_var
            << " sizeof(signed_ll_int_var): " << sizeof(signed_ll_int_var)
            << std::endl;
  unsigned long long int unsigned_ll_int_var{0};
  std::cout << "unsigned_ll_int_var: " << unsigned_ll_int_var
            << " sizeof(unsigned_long_int): " << sizeof(unsigned_ll_int_var)
            << std::endl;
}
