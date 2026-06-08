/*
 * PROJECT : EXERCISES
 * FILE    : 1.class_define_object_created.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-02-11
 * BRIEF   : 类的定义与对象的创建 
 */
#include <iostream>
#include <string>
class Human {
  public:
    // 成员函数
    void init_human(std::string name,int age) {
      _name = name;
      _age = age;
    }
    // 获取name
    const std::string& get_name() const {
      return _name;
    }
    // 获取age
    const int& get_age() const {
      return _age;
    }
  private:
    std::string _name;
    int _age;
};

int main() {
  Human h1;
  h1.init_human("bitofux", 20);
  std::cout << "name: " << h1.get_name() << std::endl;
  std::cout << "age: " << h1.get_age() << std::endl;

  return 0;
}
