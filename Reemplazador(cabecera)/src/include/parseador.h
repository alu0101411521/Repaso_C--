#pragma once
#include <filesystem>
#include <regex> 

#include "fichero.h"
#include "fecha.h"

class Parseador {
  public:
  // constructores 
  Parseador();

  void Parsear(const std::filesystem::path& ruta_entrada, const std::filesystem::path& ruta_cabezera);
  std::vector<std::string> Sustituir(const Fichero& fichero, const Fichero& fichero_entry);

  private:
    // metodos
    Fecha CurrentDate();
    std::string CurrentFile(const Fichero& fichero);
};
