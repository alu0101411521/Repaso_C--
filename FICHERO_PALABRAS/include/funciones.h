#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "pair.h"

class Funciones {
 public:
  // constructores
  Funciones(const std::string& ruta_fichero);
  Funciones();

  // destructores

  // cabeceras de funciones
  void MostrarConjunto();
  std::string PalabraFrecuente();
  std::string PalabraMenosFrecuente();
  void MostrarPalabraMenor(std::ostream& os,const int tamanio);
  void MostrarPalabra(std::ostream& os, const int tamanio);
  int MostrarContador(const std::string& aux_);

  //Modificacion: Sobrecarga de operador signo + y - |
    // funciones1 + funciones2 = {{palabra, 12}} + {{palabra1, 12}, {palabra, 10}} 
    //  -> {{palabra, 12 + 10}, {palabra1, 12}}
    // {{palabra, 12}} - {{palabra1, 12}, {palabra, 10}}
    //  -> {{palabra1, 12}}


  friend Funciones operator+(const Funciones& f1, const Funciones& f2);
  friend Funciones operator-(const Funciones& f1, const Funciones& f2);

 private:
  std::vector<Pair> conjunto;
};

#endif