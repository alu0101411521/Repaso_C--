#include "scrabble.h"
#include <iostream>

// ./programa buenas
int main(int argc, char const *argv[]){
  Scrabble calculadora(argv[1]);
  std::cout << calculadora.Puntuacion(argv[2]) << std::endl;
  calculadora.Exportar();
  return 0;
}
