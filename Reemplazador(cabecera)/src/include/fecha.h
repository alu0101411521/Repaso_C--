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