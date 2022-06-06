#include <iostream>

#include "../include/funciones.h"

// ./programa hola.txt
//  argc = 2;
//  argv = [
//    "programa",
//    "hola.txt"
//  ]

int main(int argc, char* argv[]) {
  std::string nombre_fichero = argv[1];
  Funciones aux(nombre_fichero);
  std::string ejemplo = "palabra";
  aux.MostrarConjunto();
  std::cout << "=================" << std::endl;
  std::cout << "La palabra mas frecuente es : "<< aux.PalabraFrecuente() << " . "<< std::endl;
  std::cout << "La palabra menos frecuente es : "<< aux.PalabraMenosFrecuente() << " . " << std::endl;
  std::cout << "=================" << std::endl;
  std::cout << "Las palabras menores a  8 son: ";
  aux.MostrarPalabraMenor(std::cout, 8);
  std::cout << std::endl;
  std::cout << "=================" << std::endl;
  aux.MostrarPalabra(std::cout, 5);
  std::cout << std::endl;
  std::cout << "=================" << std::endl;
  std::cout << "Veces que aparece palabra: " << aux.MostrarContador(ejemplo) << std::endl;
  return 0;
}