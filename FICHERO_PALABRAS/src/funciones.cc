#include "../include/funciones.h"
// cosntructores
Funciones::Funciones(const std::string& ruta_fichero) {
  std::fstream fichero(ruta_fichero, std::ios_base::in);
  if (!fichero.is_open()) std::cerr << "Fallo al cargar el fichero\n";
  std::string palabra_leida;
  bool fue_encontrado = false;
  while (!fichero.eof()) {
    fichero >> palabra_leida;
    // Procesar palabra leida
    // Comprobar si la palabra esta en el vector de pares
    for (int i = 0; i < conjunto.size(); ++i) {  // [a, b, c, d] // b
      if (palabra_leida == conjunto[i].palabra) {
        ++conjunto[i].contador;  // Si esta la palabra incrementamos su contador
        fue_encontrado = true;
        break;
      }
    }
    // Si no lo esta metemos {1 , palabra}
    if (!fue_encontrado) {
      conjunto.emplace_back(1, palabra_leida);
      // Pair aux(1, palabra_leida);
      // conjunto.push_back(aux);
    }
    fue_encontrado = false;
  }
  fichero.close();
}

Funciones::Funciones() {}

// funciones
void Funciones::MostrarConjunto() {
  for (int i = 0; i < conjunto.size(); ++i) {
    std::cout << "{" << conjunto[i].palabra << " , " << conjunto[i].contador
              << "}\n";
  }
}

std::string Funciones::PalabraFrecuente() {
  Pair auxiliar;
  if (conjunto.size() != 0) {
    auxiliar.contador = conjunto[0].contador;
    auxiliar.palabra = conjunto[0].palabra;
  } else {
    return "";
  }
  for (int i = 0; i < conjunto.size(); ++i) {
    if (conjunto[i].contador > auxiliar.contador) {
      auxiliar.contador = conjunto[i].contador;
      auxiliar.palabra = conjunto[i].palabra;
    }
  }
  return auxiliar.palabra;
}

std::string Funciones::PalabraMenosFrecuente() {
  Pair auxiliar;
  if (conjunto.size() != 0) {
    auxiliar.contador = conjunto[0].contador;
    auxiliar.palabra = conjunto[0].palabra;
  } else {
    return "";
  }
  for (int i = 0; i < conjunto.size(); ++i) {
    if (conjunto[i].contador < auxiliar.contador) {
      auxiliar.contador = conjunto[i].contador;
      auxiliar.palabra = conjunto[i].palabra;
    }
  }
  return auxiliar.palabra;
}

void Funciones::MostrarPalabraMenor(std::ostream& os, const int tamanio) {
  std::string auxiliar;
  for (int i = 0; i < conjunto.size(); ++i) {
    auxiliar = conjunto[i].palabra;
    if (auxiliar.size() < tamanio) {
      os << auxiliar << '\t';
    }
  }
}

void Funciones::MostrarPalabra(std::ostream& os, const int tamanio) {
  std::string auxiliar;
  for (int i = 0; i < conjunto.size(); ++i) {
    auxiliar = conjunto[i].palabra;
    if (auxiliar.size() > tamanio) {
      os << auxiliar << '\t';
    }
  }
}

int Funciones::MostrarContador(const std::string& aux_) {
  int contador_auxiliar = 0;
  for (int i = 0; i < conjunto.size(); ++i) {
    if (aux_ == conjunto[i].palabra) {
      contador_auxiliar = conjunto[i].contador;
      break;
    }
  }
  return contador_auxiliar;
}

// Modificacion: Sobrecarga de operador signo + y - |
// funciones1 + funciones2 = {{palabra, 12}} + {{palabra1, 12}, {palabra, 10}}
//  -> {{palabra, 12 + 10}, {palabra1, 12}}
// {{palabra, 12}} - {{palabra1, 12}, {palabra, 10}}
//  -> {{palabra1, 12}}

Funciones operator+(const Funciones& f1, const Funciones& f2) {
  Funciones resultado;
  Pair auxiliar;
  Pair auxiliar1;
  bool fue_encontrado = false;

  // Comparar todos los elementos de f1 con f2
  for (int i = 0; i < f1.conjunto.size(); ++i) {
    for (int j = 0; j < f2.conjunto.size(); ++j) {
      if (f1.conjunto[i].palabra == f2.conjunto[j].palabra) {
        auxiliar.palabra = f1.conjunto[i].palabra;
        auxiliar.contador = f1.conjunto[i].contador + f2.conjunto[j].contador;
        resultado.conjunto.push_back(auxiliar);
        fue_encontrado = true;
        break;
      }
    }
    if (!fue_encontrado) {
      auxiliar.palabra = f1.conjunto[i].palabra;
      auxiliar.contador = f1.conjunto[i].contador;
      resultado.conjunto.push_back(auxiliar);
    }
    fue_encontrado = false;
  }

  // Comparar todos los elementos de f2 con f1
  // Cuidado con  meter elementos que ya existen en el conjunto de resultado
 for (int i = 0; i < f2.conjunto.size(); ++i) {
    for (int j = 0; j < f1.conjunto.size(); ++j) {
      if (f2.conjunto[i].palabra == f1.conjunto[j].palabra) {
        auxiliar.palabra = f2.conjunto[i].palabra;
        auxiliar.contador = f2.conjunto[i].contador + f2.conjunto[j].contador;
        resultado.conjunto.push_back(auxiliar);
        fue_encontrado = true;
        break;
      }
    }
    if (!fue_encontrado) {
      auxiliar.palabra = f2.conjunto[i].palabra;
      auxiliar.contador = f2.conjunto[i].contador;
      resultado.conjunto.push_back(auxiliar);
    }
    fue_encontrado = false;
  }

  return resultado;
}

Funciones operator-(const Funciones& f1, const Funciones& f2) {

}