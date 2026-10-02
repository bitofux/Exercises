/*
 * PROJECT : EXERCISES
 * FILE    : 4.integer.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-10-02
 * BRIEF   : 普通 integer 类
 */
#include <iostream>

class Integer {
  private:
    int value_ = 0;
    // Integer(const Integer&);
    // Integer& operator=(const Integer&);
  public:
    Integer () = default;
    Integer(int value) {
      value_ = value;
    }
    Integer(const Integer&) = delete;
    Integer& operator=(const Integer&) = delete;

    void SetValue(int value) {
      value_ = value;
    }

    void SetValue(float value) = delete;

};

int main() {
  // 调用无参构造函数
  Integer i1;
  i1.SetValue(10);
  i1.SetValue(10.2f);
}
