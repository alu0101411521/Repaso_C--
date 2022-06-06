#include <iostream>

#include "../include/tablero.h"

int main() {
  Tablero tablero;
  int x{5}, y{5};
  bool dead{false};
  Celula celula(x, y, dead);
  std::cout << tablero << std::endl;
  tablero.ModificarCeldaTablero(celula);
  std::cout << "====================" << std::endl;
  std::cout << tablero << std::endl;

  return 0;
}
