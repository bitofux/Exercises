#include <iostream>

namespace ICBC {
int g_money = 1000;
void save(int money) { g_money += money; }
void pay(int money) { g_money -= money; }
} // namespace ICBC

namespace CCB {
int g_money = 1000;
void save(int money) { g_money += money; }
void pay(int money) { g_money -= money; }
} // namespace CCB

int main() {
  ICBC::save(2000);
  std::cout << "ICBC::g_money = " << ICBC::g_money << std::endl;
  ICBC::pay(500);
  std::cout << "ICBC::g_money = " << ICBC::g_money << std::endl;

  CCB::save(1500);
  std::cout << "CCB::g_money = " << CCB::g_money << std::endl;
  CCB::pay(300);
  std::cout << "CCB::g_money = " << CCB::g_money << std::endl;
}
