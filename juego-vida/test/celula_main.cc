#include <iostream>

#include "../include/celula.h"

int main() {
  Celula celula1;
  int x{3}, y{4};
  bool dead = false;
  Celula celula2(x, y, dead);
  int new_x{8}, new_y{9};
  bool alive = true;
  std::cout << "================" << std::endl;
  std::cout << celula1 << std::endl;
  std::cout << "================" << std::endl;
  std::cout << celula2 << std::endl;
  std::cout << "================" << std::endl;
  celula2.ChangePosition(new_x, new_y);
  std::cout << celula2 << std::endl;
  std::cout << "================" << std::endl;
  celula2.ChangeState(alive);
  std::cout << celula2 << std::endl;
  std::cout << "================" << std::endl;
  std::cout << celula1.GetPositionX() << " " << celula1.GetPositionY() << " "
            << celula1.GetState() << std::endl;
  return 0;
}
