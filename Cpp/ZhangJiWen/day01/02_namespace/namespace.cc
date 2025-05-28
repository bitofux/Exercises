#include "namespace.h"
#include <cstddef>

const char *mylib::library_name = "mylib";

mylib::Counter::Counter() = default;

void mylib::Counter::increment() {++count_;}

std::size_t mylib::Counter::value() const {return count_;}

int mylib::add(int a, int b){ return a + b;}




