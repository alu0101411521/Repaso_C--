#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

class Calculo {
 public:
  // cosntructores
  Calculo(const std::string& ruta);

  // declaracion de metodos
  std::vector<double> Multiply(double num);

  void Export(double num, const std::string& ruta,
              const std::vector<double>& resultado);

  std::vector<double> GetNumeros();

 private:
  double num_;
  std::vector<double> valores_fichero;
};