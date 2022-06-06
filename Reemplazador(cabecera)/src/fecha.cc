#include "fecha.h"

// https://www.cplusplus.com/reference/chrono/duration/duration/

// constructores
Fecha::Fecha() { today_ = std::chrono::system_clock::now(); }

// metodos
Fecha Fecha::FechaActual() { return Fecha(); }

time_t Fecha::CalcularFecha() const {
  // https://en.cppreference.com/w/cpp/chrono/system_clock/to_time_t
  time_t resultado;
  resultado = std::chrono::system_clock::to_time_t(today_);
  return resultado;
}

// metodo para convertir el objeto al string
std::string Fecha::ToString() const {
  std::string resultado;
  time_t tt = CalcularFecha();
  resultado = ctime(&tt);
  return resultado;
}