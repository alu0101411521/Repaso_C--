#include <iostream>
#include <string>

#include "ficheros.h"

int main(int argc, char const *argv[]) {
  std::vector<double> auxiliar;
  std::vector<double> resultado;

  double numero = std::stoi(argv[3]);
  Calculo calcular(argv[1]);
  resultado = calcular.GetNumeros();
  auxiliar = calcular.Multiply(numero);
  calcular.Export(numero, argv[2], auxiliar);

  // modificacion
  for (int i = 0; i < auxiliar.size(); ++i) {
    std::cout << resultado[i] << " x " << numero << " = " << auxiliar[i]
              << std::endl;
  }
  return 0;
}
