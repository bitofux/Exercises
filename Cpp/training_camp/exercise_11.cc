//定义一个union,包含int,float和char类型的成员.编写一个程序,允许用户选择数据类型(通过输入),然后根据选择输入相应的值,并输出该值
#include <cstring>
#include <iostream>

union Bitofux {
  int id;
  float price;
  char character;
};

enum Type {
  INT,
  FLOAT,
  CHAR,
  NON
};

Type typeToInt(const char* type_name) {
  if (!strcmp(type_name, "int")) {
    return INT;
  } else if (!strcmp(type_name, "float")) {
    return FLOAT;
  } else if (!strcmp(type_name, "char")) {
    return CHAR;
  }
  return NON;
}

int main() {
  char type_name[10] = {'\0'};
  Bitofux b1;

  std::cout << "*********\n";
  std::cout << "  INT  \n";
  std::cout << "  FLOAT  \n";
  std::cout << "  CHAR  \n";
  std::cout << "*********\n";
  
  std::cout << "输入一个上述的类型: ";
  std::cin >> type_name;
  
  Type type = typeToInt(type_name);
  switch (type) {
    case INT:
      std::cout << "输入上述你选择类型相应的值: ";
      std::cin >> b1.id;
      std::cout << "b1.id: " << b1.id << "\n";
      break;
    case FLOAT:
      std::cout << "输入上述你选择类型相应的值: ";
      std::cin >> b1.price;
      std::cout << "b1.price: " << b1.price << "\n";
      break;
    case CHAR:
      std::cout << "输入上述你选择类型相应的值: ";
      std::cin >> b1.character;
      std::cout << "b1.character: " << b1.character << "\n";
      break;
    case NON:
      std::cout << "输入类型错误!\n";
      break;
  }

  return 0;
}
