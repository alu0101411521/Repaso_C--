#pragma once

#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

class Fichero {
 public:
  // constructores
  Fichero();
  Fichero(const std::filesystem::path& ruta);

  // metodos
  void Abrir(const std::filesystem::path& ruta);
  void Guardar();

  // metodos que devuelve el nombre del fichero
  std::string NombreFichero() const;

  Fichero Introducir(std::vector<std::string>& cabecera);
  std::vector<std::string> Contenido() const;

  // sobrecarga de operadores
  friend std::ostream& operator<<(std::ostream& os, const Fichero& fichero);
  friend std::istream& operator>>(std::istream& is, Fichero& fichero);

 private:
  std::filesystem::path ruta_;
  std::vector<std::string> texto_;
  std::string nombre_;
};