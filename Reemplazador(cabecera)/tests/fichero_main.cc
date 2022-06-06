#include <filesystem>
#include <iostream>

#include "fichero.h"

int main(int argc, char* argv[]) {

  std::filesystem::path ruta(argv[1]);
  Fichero fichero(ruta);
  std::cout << fichero << std::endl;
  return 0;
}
