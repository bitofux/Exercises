#include <iostream>
#include <type_traits>

struct foo {
  int i{10};
};

foo fo;
int main() {
  if constexpr (std::is_lvalue_reference_v<decltype((std::move(fo)))>) {
    std::cout << "这是一个左值!\n";
  } else if constexpr (std::is_rvalue_reference_v<decltype(std::move(fo))>) {
    std::cout << "这是一个将亡值!\n";
  } else {
    std::cout << "这是一个纯右值\n";
  }
}
