#ifndef _NAMESPACE_H_
#define _NAMESPACE_H_
#include <cstddef>
#include <iostream>
namespace mylib {
extern const char *library_name;
class Counter {
private:
  std::size_t count_{0};

public:
  Counter();
  void increment();
  std::size_t value() const;
};

int add(int a,int b);
} // namespace mylib

#endif
