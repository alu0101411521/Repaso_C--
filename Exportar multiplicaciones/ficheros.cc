#include "ficheros.h"

// constructores
Calculo::Calculo(const std::string& ruta) {
  std::ifstream fichero_entrada(ruta);
  if (fichero_entrada.is_open()) {
    double number;
    while (!fichero_entrada.eof()) {
      fichero_entrada >> number;
      valores_fichero.push_back(number);
    }
  }
  fichero_entrada.close();
}

// declaracion de  metodos
std::vector<double> Calculo::Multiply(double num) {
  std::vector<double> resultado;
  double operacion{0};
  for (int i = 0; i < valores_fichero.size(); ++i) {
    operacion = valores_fichero[i] * num;
    resultado.push_back(operacion);
  }
  return resultado;
}

void Calculo::Export(double num, const std::string& ruta,
                     const std::vector<double>& resultado) {
  std::ofstream fichero_salida(ruta);
  if (fichero_salida.is_open()) {
    for (int i = 0; i < valores_fichero.size(); ++i) {
      fichero_salida << valores_fichero[i] << " x " << num << " = "
                     << resultado[i] << std::endl;
    }
  }
  fichero_salida.close();
}

std::vector<double> Calculo::GetNumeros() { return valores_fichero; }
