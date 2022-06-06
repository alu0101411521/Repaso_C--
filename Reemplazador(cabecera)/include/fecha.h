/*

Archivo entrada:
Nombre: Endika Pradera 
Correo: endikapradera@gmail.com
Fecha: Wed Mar  9 10:50:19 2022

archivo: fecha.h

*/


#pragma once

#include <chrono>
#include <iostream>
#include <string>
#include <time.h>

class Fecha {
 public:
  // constructores
  Fecha();

  // metodos
  Fecha FechaActual();
  time_t CalcularFecha() const;

  // metodo para convertir el objeto al string
  std::string ToString() const;

 private:
  std::chrono::system_clock::time_point today_;
};




