#include <iostream>
#include <type_traits>
#include <utility>

// 工具宏:打印是否左/右值引用
#define REF_KIND(T)                                                            \
  (std::is_lvalue_reference<T>::value                                          \
       ? "lvalue (&)"                                                          \
       : (std::is_rvalue_reference<T>::value ? "rvalue (&&)"                   \
                                             : "value (no ref)"))

// 1.定壳,再填类型
void shell_example() {
  int i{42};
  const int ci{100};

  //(1) 裸auto：不加壳，类型随初始化表达式而变
  auto a = i;  // T 直接推成int -->int
  auto b = ci; // T 去掉顶层const -->int

  //(2) auto*: 指针壳 T*,只有一次*
  auto *p1 = &i; //&i的类型是int*,因此T就是int ->int*
  // auto* p_err = i; //不是指针，无法匹配T*，编译报错

  //(3) auto&: 左值引用壳 T&
  auto &ref = i; // T = int -->int&(可修改)
  ref += 8;

  //(4) const auto&: 万能引用壳 const T&
  const auto &ref_var = ci;     // T = int -> const int&
  const auto &ref_const = 3.14; // T = double ->const double&(绑定临时变量)

  std::cout << "[shell_example]\n";
  std::cout << "a type: " << REF_KIND(decltype(a)) << '\n';
  std::cout << "p1 type: " << REF_KIND(decltype(p1)) << '\n';
  std::cout << "ref type: " << REF_KIND(decltype(ref)) << '\n';
  std::cout << "ref_const type: " << REF_KIND(decltype(ref_const)) << '\n';
}

// 2. 万能引用 + 引用折叠 demo_forward
template<typename T>
void demo_forward(T&& arg){
  //折叠后：左值调用->T = int&、arg = int& 右值->T=int、arg = int&&
  auto&& x = std::forward<T>(arg);

  std::cout << " T summary : "
            << (std::is_same<typename std::remove_reference<T>::type,int>::value ? "int" : "unknow")
    << ", arg is "<< REF_KIND(decltype(arg))
    << ", x is " << REF_KIND(decltype(x)) << "\n";
}

void collapse_example() {
  int i {7};

  std::cout << "[collapse_example]\n";
  std::cout << " 调左值：demo_forward(i)...\n";
  demo_forward(i); // 左值调用 -> arg为int&、x折成int&
  std::cout << " 调右值：demo_forward(123)...\n";
  demo_forward(123); //右值调用->arg为int&&,x保持int&&
  std::cout << '\n';
}
int main () {
  shell_example();
  collapse_example();

  return 0;
}
