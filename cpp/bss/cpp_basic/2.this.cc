/*
 * PROJECT : EXERCISES
 * FILE    : 2.this.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-02-11
 * BRIEF   : this指针 
 */
#include <iostream>
#include <string>
class Human {
  public:
    // 成员函数
    // void init_human(Human* const this,std::string name,int age);
    void init_human(std::string name,int age) {
      this->_name = name;
      this->_age = age;
    }
    // 获取name
    //const std::string& get_name(Human* const this) 
    const std::string& get_name() const {
      return this->_name;
    }
    // 获取age
    // const int& get_age(Human* const this)
    const int& get_age() const {
      return this->_age;
    }
  private:
    std::string _name;
    int _age;
};

int main() {
  Human h1;
  h1.init_human("bitofux", 20); // init_human(&h1,"bitofux",20);
  std::cout << "name: " << h1.get_name() << std::endl;
  std::cout << "age: " << h1.get_age() << std::endl;

  return 0;
}
