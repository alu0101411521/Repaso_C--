#include <iostream>

#include "parseador.h"

int main(int argc, char const *argv[]) {
  Parseador parsear;
  std::filesystem::path entrada(argv[1]);
  std::filesystem::path cabecera(argv[2]);
  parsear.Parsear(entrada, cabecera);

  return 0;
}
