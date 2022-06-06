#pragma once

#include <cctype>
#include <fstream>
#include <iostream>
#include <map>
#include <string>

class Scrabble {
 public:
  // constructores
  Scrabble();
  Scrabble(const std::string& ruta);

  // metodos
  int Puntuacion(const std::string& palabra);
  void Exportar();

 private:
  std::map<char, int> tabla_valores_;
};
