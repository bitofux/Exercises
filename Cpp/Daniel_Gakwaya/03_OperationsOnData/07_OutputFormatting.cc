#include <iomanip>
#include <ios>
#include <iostream>
#include <unistd.h>
int main() {

  // std::endl
  std::cout << "Hello";
  std::cout << "World";

  std::cout << std::endl;

  std::cout << "Hello" << std::endl;
  std::cout << "World" << std::endl;

  std::cout << std::endl;

  //\n
  std::cout << "Hello\n";
  std::cout << "World\n";

  // std::flush
  std::cout << "Hello std::flush\n" << std::flush;
  /*sleep(2);*/

  // std::setw()
  std::cout << "Unformatted table : " << '\n';
  std::cout << "Daniel" << "Gray" << "25" << '\n';
  std::cout << "Stanley" << "Woods" << "33" << '\n';
  std::cout << "Jordan" << "Parker" << "45" << '\n';
  std::cout << "Joe" << "Ball" << "21" << '\n';
  std::cout << "Josh" << "Carr" << "27" << '\n';
  std::cout << "Izaiah" << "Robinson" << "29" << '\n';

  std::cout << '\n';
  std::cout << "Formatted table( Default Right-Justified) : " << '\n';
  /*std::cout << std::left;*/
  std::cout << std::setw(9) << "Lastname" << std::setw(10) << "Firstname"
            << std::setw(4) << "age" << '\n';
  std::cout << std::setw(9) << "Daniel" << std::setw(10) << "Gray"
            << std::setw(4) << "25" << '\n';
  std::cout << std::setw(9) << "Stanley" << std::setw(10) << "Woods"
            << std::setw(4) << "33" << '\n';
  std::cout << std::setw(9) << "Jordan" << std::setw(10) << "Parker"
            << std::setw(4) << "45" << '\n';
  std::cout << std::setw(9) << "Joe" << std::setw(10) << "Ball" << std::setw(4)
            << "21" << '\n';
  std::cout << std::setw(9) << "Josh" << std::setw(10) << "Carr" << std::setw(4)
            << "27" << '\n';
  std::cout << std::setw(9) << "Izaiah" << std::setw(10) << "Robinson"
            << std::setw(4) << "29" << '\n';

  // internal justified : sign is left justified,data is right justified
  std::cout << std::right;
  std::cout << "std::internal" << '\n';
  std::cout << std::setw(8) << -123.44 << '\n';
  std::cout << std::internal;
  std::cout << std::setw(8) << -123.44 << '\n';
  std::cout << std::flush;
  // std::setfill

  std::cout << std::right;
  std::cout << std::setfill('-');
  std::cout << std::setw(9) << "Lastname" << std::setw(10) << "Firstname"
            << std::setw(4) << "age" << '\n';
  std::cout << std::setw(9) << "Daniel" << std::setw(10) << "Gray"
            << std::setw(4) << "25" << '\n';
  std::cout << std::setw(9) << "Stanley" << std::setw(10) << "Woods"
            << std::setw(4) << "33" << '\n';
  std::cout << std::setw(9) << "Jordan" << std::setw(10) << "Parker"
            << std::setw(4) << "45" << '\n';
  std::cout << std::setw(9) << "Joe" << std::setw(10) << "Ball" << std::setw(4)
            << "21" << '\n';
  std::cout << std::setw(9) << "Josh" << std::setw(10) << "Carr" << std::setw(4)
            << "27" << '\n';
  std::cout << std::setw(9) << "Izaiah" << std::setw(10) << "Robinson"
            << std::setw(4) << "29" << '\n';

  // std::cout << std::boolalpha
  bool condition{true};
  bool other_condition{false};
  std::cout << "condition : " << condition << '\n';
  std::cout << "other_condition : " << other_condition << '\n';

  std::cout << std::boolalpha;
  std::cout << "condition : " << condition << '\n';
  std::cout << "other_condition : " << other_condition << '\n';
  std::cout << std::noboolalpha;
  std::cout << "condition : " << condition << '\n';
  std::cout << "other_condition : " << other_condition << '\n';
  // std::showpos
  signed int number{20};
  double dou{20.22};
  std::cout << std::showpos;
  std::cout << "number: " << number << std::endl;
  std::cout << "dou : " << dou << std::endl;
  std::cout << std::noshowpos;
  std::cout << "number: " << number << '\n';

  // std::dec std::hex std::oct
  int pos_int{717171};
  int neg_int{-10};
  double double_var{498.32};

  std::cout << std::endl;
  std::cout << "pos_int in different base : " << std::endl;
  std::cout << "pos_int (dec) : " << std::dec << pos_int << std::endl;
  std::cout << "pos_int (hex) : " << std::hex << pos_int << std::endl;
  std::cout << "pos_int (oct) : " << std::oct << pos_int << std::endl;

  std::cout << std::endl;
  std::cout << "neg_int in different base : " << std::endl;
  std::cout << "neg_int (dec) : " << std::dec << neg_int << std::endl;
  std::cout << "neg_int (hex) : " << std::hex << neg_int << std::endl;
  std::cout << "neg_int (oct) : " << std::oct << neg_int << std::endl;

  std::cout << std::endl;
  std::cout << "double_var in different base : " << std::endl;
  std::cout << "double_var (dec) : " << std::dec << double_var << std::endl;
  std::cout << "double_var (hex) : " << std::hex << double_var << std::endl;
  std::cout << "double_var (oct) : " << std::oct << double_var << std::endl;

  //std::showbase std::uppercase
  std::cout << std::showbase;
  std::cout << "pos_int in different base : " << std::endl;
  std::cout << "pos_int (dec) : " << std::dec << pos_int << std::endl;
  std::cout << "pos_int (hex) : " << std::hex << pos_int << std::endl;
  std::cout << "pos_int (oct) : " << std::oct << pos_int << std::endl;
  std::cout << std::showbase << std::uppercase;
  std::cout << "pos_int in different base : " << std::endl;
  std::cout << "pos_int (dec) : " << std::dec << pos_int << std::endl;
  std::cout << "pos_int (hex) : " << std::hex << pos_int << std::endl;
  std::cout << "pos_int (oct) : " << std::oct << pos_int << std::endl;

  //std::scientific std::fixed
  double a {3.1415926535897932};
  double b {2006.0};
  double c {1.34e-10};
  std::cout << std::endl;
  std::cout << "double values (default) : " << std::endl;
  std::cout << "a : " << a << std::endl;
  std::cout << "b : " << b << std::endl;
  std::cout << "c : " << c << std::endl;

  std::cout << std::endl;
  std::cout << std::fixed;
  std::cout << "double values (fixed) : " << std::endl;
  std::cout << "a : " << a << std::endl;
  std::cout << "b : " << b << std::endl;
  std::cout << "c : " << c << std::endl;
  
  std::cout << std::endl;
  std::cout << "double values (scientific) : " << std::endl;
  std::cout << std::scientific;
  std::cout << "a : " << a << std::endl;
  std::cout << "b : " << b << std::endl;
  std::cout << "c : " << c << std::endl;

  std::cout << std::endl;
  std::cout << "double values (back to defaults) : " << std::endl;
  std::cout.unsetf(std::ios::scientific | std::ios::fixed);
  std::cout << "a : " << a << std::endl;
  std::cout << "b : " << b << std::endl;
  std::cout << "c : " << c << std::endl;
  
  //std::setprecision
  a = 3.1415926535897932384626433832795;
  std::cout << std::endl;
  std::cout << "a (default precision(6)) : " << a << std::endl;
  std::cout << std::setprecision(10);
  std::cout << "a (default precision(10)) : " << a << std::endl;
  std::cout << std::setprecision(20);
  std::cout << "a (default precision(20)) : " << a << std::endl;

  //reset precision to six
  std::cout << std::setprecision(6) << std::endl;
  //std::showpoint
  double d {34.1};
  double e {101.99};
  double f {12.0};
  int g {45};
  std::cout << std::dec;
  std::cout << "noshowpoint(default) : " << std::endl;
  std::cout << "d : " << d << std::endl;
  std::cout << "e : " << e << std::endl;
  std::cout << "f : " << f << std::endl;
  std::cout << "g : " << g << std::endl;

  std::cout << std::endl;
  std::cout << "showpoint : " << std::endl;
  std::cout << std::showpoint;
  std::cout << "d : " << d << std::endl;
  std::cout << "e : " << e << std::endl;
  std::cout << "f : " << f << std::endl;
  std::cout << "g: " << g << std::endl;
  return 0;
}
