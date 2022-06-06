#include "../include/vida_juego.h"

int main() {
  Juego juegoSB(10, 10, 5, {0, 0, 2, 5, 1}, {0, 1, 2, 5, 2});
  int n = 140;
  Juego juegoAM;
  Celula celula(0, 0, false);
  Celula celula2(0, 1, false);
  std::cout << juegoSB << std::endl;
  std::cout << juegoSB.CelulaVecina(celula) << std::endl;
  std::cout << juegoSB.CelulaVecina(celula2) << std::endl;
  std::cout << "==========" << std::endl;
  std::cout << std::endl;
  juegoSB.SandBox(100, 30, 3, 5, {0, 0, 2, 5, 1}, {0, 1, 2, 5, 2});

  return 0;
}

