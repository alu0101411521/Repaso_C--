#include "scrabble.h"

// Constructores
Scrabble::Scrabble() {
  tabla_valores_ = {{'A', 1},  {'E', 1}, {'I', 1}, {'O', 1}, {'U', 1}, {'L', 1},
                    {'N', 1},  {'R', 1}, {'S', 1}, {'T', 1}, {'D', 2}, {'G', 2},
                    {'B', 3},  {'C', 3}, {'M', 3}, {'P', 3}, {'F', 4}, {'H', 4},
                    {'V', 4},  {'W', 4}, {'Y', 4}, {'K', 5}, {'J', 8}, {'X', 8},
                    {'Z', 10}, {'Q', 10}};
}

Scrabble::Scrabble(const std::string& ruta) {
  std::ifstream fichero(ruta);
  if (fichero.is_open()) {
    // fichero -> variables basicas -> variables complejas
    char number;
    int valor;
    while (!fichero.eof()) {
      fichero >> number >> valor;
      tabla_valores_.insert(std::make_pair(number, valor));
      // tabla_valores_[number] = valor;
    }
  } else {
    // error
  }
  fichero.close();
}

// Declaracion de metodos
int Scrabble::Puntuacion(const std::string& palabra) {
  int resultado{0};
  std::string auxiliar = palabra;

  // Pasar a mayuscula el string
  for (int i = 0; i < auxiliar.length(); ++i) {
    auxiliar[i] = toupper(auxiliar[i]);
  }

  // Recorremos el mapa en busca de la puntuacion
  for (int i = 0; i < auxiliar.length(); ++i) {
    resultado += tabla_valores_.at(auxiliar[i]);
  }
  return resultado;
}

// tabla.x
void Scrabble::Exportar() {
  // variables complejas -> variables sencillas -> fichero;
  std::ofstream fichero_salida("tabla.x");
  if (fichero_salida.is_open()) {
    for (std::map<char, int>::iterator it = tabla_valores_.begin();
         it != tabla_valores_.end(); it++) {
        char letra = it->first;
        int numero = it->second;
        fichero_salida << letra << " " <<  numero << std::endl;; 
    }
  } else {
    // error
  }
  fichero_salida.close();
}